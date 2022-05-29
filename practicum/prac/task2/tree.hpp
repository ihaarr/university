#ifndef TEST_TREE_HPP
#define TEST_TREE_HPP
#include <cstring>
#include "btree_stack.hpp"
typedef void(*tree_visit_f)(const btree*);
struct btree_stack;
struct btree {
    btree* parent;
    btree* left;
    btree* right;
    char str[32];
};
void node_free(const btree* node);
btree** btree_init();
bool btree_is_empty(btree* root);
void btree_add(btree** root, const char* str);
btree* btree_find(btree** root, const char* str);
void btree_delete(btree** root, const char* str);
void btree_preorder(btree** root, tree_visit_f f);
void btree_inorder(btree** root, tree_visit_f f);
void btree_postorder(btree** root, tree_visit_f f);
void btree_free(btree** root);

void node_free(const btree* node) {delete node;}
btree** btree_init() {
    btree** tree = new btree*;
    *tree = nullptr;
    return tree;
}
bool btree_is_empty(btree** root) {
    if(root == nullptr) return true;
    return *root == nullptr;
}
void btree_add(btree** root, const char* str) {
    if(root == nullptr) return;
    btree* el = new btree;
    strcpy(el->str, str);
    el->left = nullptr;
    el->right = nullptr;
    if(*root == nullptr) {
        el->parent = nullptr;
        *root = el;
        return;
    }
    int len = strlen(str);
    bool to_right = false;
    btree* curr = *root;
    btree* prev = curr;
    while(curr != nullptr) {
        prev = curr;
        if(strlen(curr->str) <= len) {
            curr = curr->right;
            to_right = true;
        } else {
            curr = curr->left;
            to_right = false;
        }
    }
    el->parent = prev;
    if(to_right) {
        prev->right = el;
    } else {
        prev->left = el;
    }
}
btree* btree_find(btree** root, const char* str) {
    if(root == nullptr) return nullptr;
    if(*root == nullptr) return nullptr;
    int len = strlen(str);
    btree* curr = *root;
    while(curr != nullptr) {
        if(strcmp(curr->str, str) == 0) {
            return curr;
        }
        if(strlen(curr->str) < len ) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return nullptr;
}
void btree_delete(btree** root, const char* str) {
    if(root == nullptr) return;
    if(*root == nullptr) return;
    btree* el = btree_find(root, str);
    if(el == nullptr) return;
    if(el == *root) {
        if(el->right == nullptr && el->left == nullptr) {
            *root = nullptr;
            delete el;
            return;
        }
        if(el->right != nullptr && el->left == nullptr) {
            *root = el->right;
            el->right->parent = nullptr;
            delete el;
            return;
        }
        if(el->right == nullptr && el->left != nullptr) {
            *root = el->left;
            el->left->parent = nullptr;
            delete el;
            return;
        }
        btree* del = el;
        el = el->right;
        while(el->left != nullptr) {
            el = el->left;
        }
        strcpy(del->str, el->str);
        if(del->right == el) {
            if(del->right->right != nullptr) {
                del->right = del->right->right;
            } else {
                del->right = nullptr;
            }
            delete el;
        } else {
            delete el->parent->left;
            el->parent->left = nullptr;
        }
        return;
    }
    if(el->left == nullptr && el->right == nullptr) {
        if(el->parent->right == el) {
            el->parent->right = nullptr;
        } else {
            el->parent->left = nullptr;
        }
        delete el;
        return;
    } else {
        if(el->left == nullptr && el->right != nullptr) {
            el->parent->right = el->right;
            delete el;
            return;
        }
        if(el->left != nullptr && el->right == nullptr){
            el->parent->left = el->left;
            delete el;
            return;
        }
        btree* del = el;
        el = el->right;
        while(el->left != nullptr) {
            el = el->left;
        }
        strcpy(del->str, el->str);
        if(del->right == el) {
            if(el->right != nullptr) {
                del->right = el->right;
            } else {
                del->right = nullptr;
            }
            delete el;
        } else {
            delete el->parent->left;
            el->parent->left = nullptr;
        }
        return;
    }
}
void btree_preorder(btree** root, tree_visit_f f) {
    if(root == nullptr) return;
    if(*root == nullptr) return;
    btree_stack** stack = stack_init();
    btree* node = *root;
    stack_push(stack, node);
    while(!stack_is_empty(stack)) {
        node = stack_pop(stack);
        if(node->right != nullptr) stack_push(stack, node->right);
        if(node->left != nullptr) stack_push(stack, node->left);
        if(f != nullptr) f(node);
    }
}
void btree_inorder(btree** root, tree_visit_f f) {
    if(root == nullptr) return;
    if(*root == nullptr) return;
    btree_stack* s = nullptr;
    btree_stack** stack = &s;
    btree* node = *root;
    while(!stack_is_empty(stack) || node != nullptr) {
        if(node != nullptr) {
            stack_push(stack, node);
            node = node->left;
        } else {
            node = stack_pop(stack);
            if(f != nullptr) f(node);
            node = node->right;
        }
    }
}
void btree_postorder(btree** root, tree_visit_f f) {
    if(root == nullptr) return;
    if(*root == nullptr) return;
    btree_stack* s = nullptr;
    btree_stack** stack = &s;
    btree* node = *root;
    btree* peek;
    btree* last_visited = nullptr;
    while(!stack_is_empty(stack) || node) {
        if(node != nullptr) {
            stack_push(stack, node);
            node = node->left;
        } else {
            peek = stack_top(stack);
            if(peek->right != nullptr && last_visited != peek->right) {
                node = peek->right;
            } else {
                if(f != nullptr) f(peek);
                last_visited = stack_pop(stack);
            }
        }
    }
}
void btree_free(btree** root) {
    btree_postorder(root, node_free);
    delete root;
}
#endif //TEST_TREE_HPP
