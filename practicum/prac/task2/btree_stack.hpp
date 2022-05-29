#ifndef TEST_BTREE_STACK_HPP
#define TEST_BTREE_STACK_HPP
struct btree;
struct btree_stack {
    btree_stack* prev;
    btree* node;
};
bool stack_is_empty(btree_stack** top) {
    return *top == nullptr;
}
btree_stack** stack_init() {
    btree_stack** stack = new btree_stack*;
    *stack = nullptr;
    return stack;
}
void stack_push(btree_stack** top, btree* node) {
    btree_stack* newtop = new btree_stack;
    newtop->node = node;
    newtop->prev = *top;
    *top = newtop;
}
btree* stack_pop(btree_stack** top) {
    btree_stack* oldtop = *top;
    btree* ret = oldtop->node;
    *top = (*top)->prev;
    delete oldtop;
    return ret;
}
btree* stack_top(btree_stack** top) {
    if(top == nullptr) return nullptr;
    if(*top == nullptr) return nullptr;
    return (*top)->node;
}
void stack_free(btree_stack** top) {
    while(!stack_is_empty(top)) {
        stack_pop(top);
    }
    delete top;
}
#endif //TEST_BTREE_STACK_HPP
