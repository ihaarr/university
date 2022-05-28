//
// Created by Igor on 27.05.2022.
//

#ifndef TEST_TREE_HPP
#define TEST_TREE_HPP
#include <cstring>
#include "btree_stack.hpp"
typedef void(*tree_visit_f)(const btree*);
struct btree_stack;
struct btree {
    btree* left;
    btree* right;
    char str[32];
};

bool tree_is_empty(btree* root);
void tree_add(btree** root, char* str);
btree* tree_find(btree** root, const char* str);
void tree_delete(btree** root, const char* str);
void tree_preorder(btree** root, tree_visit_f f);
void tree_inorder(btree** root, tree_visit_f f);
void tree_postorder(btree** root, tree_visit_f f);

bool tree_is_empty(btree* root) { return root == nullptr;}
void tree_add(btree** root, char* str) {
    if(root == nullptr) return;
    btree* el = new btree;
    strcpy(el->str, str);
    el->left = nullptr;
    el->right = nullptr;
    if(*root == nullptr) {
        *root = el;
        return;
    }
    int len = strlen(str);
    bool to_right = false;
    btree* curr = *root;
    btree* prev;
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
    if(to_right) {
        prev->right = el;
    } else {
        prev->left = el;
    }
}
btree* tree_find(btree** root, const char* str) {
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
void tree_delete(btree** root, const char* str) {
    if(root == nullptr) return;
    if(*root == nullptr) return;
    btree* curr = *root;
    btree* prev = curr;
    int len = strlen(str);
    bool isRight = false;
    while(curr != nullptr) {
        if(strcmp(curr->str, str) == 0) {
            break;
        }
        prev = curr;
        if(strlen(curr->str) < len ) {
            curr = curr->right;
            isRight = true;
        } else {
            curr = curr->left;
            isRight = false;
        }
    }
    if(curr == nullptr) return;
    if(curr == *root) {
        if(prev->right == nullptr && prev->left == nullptr) {
            *root = nullptr;
            return;
        }
        if(prev->right != nullptr && prev->left == nullptr) {
            *root = prev->right;
            return;
        }
        if(prev->right == nullptr && prev->left != nullptr) {
            *root = prev->left;
            return;
        }
        btree* del = prev;
        btree* pr;
        prev = prev->right;
        while(prev->left != nullptr) {
            pr = prev;
            prev = prev->left;
        }
        strcpy(del->str, prev->str);
        if(del->right == prev) {
            if(del->right->right != nullptr) {
                del->right = del->right->right;
            } else {
                del->right = nullptr;
            }
        } else {
            pr->left = nullptr;
        }
        delete prev;
        return;
    }
    if(curr->left == nullptr && curr->right == nullptr) {
        if(isRight) {
            prev->right = nullptr;
        } else {
            prev->left = nullptr;
        }
        delete curr;
        return;
    } else {
        if(curr->left == nullptr && curr->right != nullptr) {
            prev->right = curr->right;
            delete curr;
            return;
        }
        if(curr->left != nullptr && curr->right == nullptr){
            prev->left = curr->left;
            delete curr;
            return;
        }
        btree* del = curr;
        btree* pr;
        prev = prev->right;
        while(prev->left != nullptr) {
            pr = prev;
            prev = prev->left;
        }
        strcpy(del->str, prev->str);
        delete pr->left;
        pr->left = nullptr;
        return;
    }
}
void tree_preorder(btree** root, tree_visit_f f) {
    if(*root == nullptr) return;
    btree_stack* s = nullptr;
    btree_stack** stack = &s;
    btree* node;
    stack_push(stack, *root);
    while(!stack_is_empty(stack)) {
        node = stack_pop(stack);
        if(node->right != nullptr) stack_push(stack, node->right);
        if(node->left != nullptr) stack_push(stack, node->left);
        if(f != nullptr) f(node);
    }
}
void tree_inorder(btree** root, tree_visit_f f) {
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
void tree_postorder(btree** root, tree_visit_f f) {
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
#endif //TEST_TREE_HPP
