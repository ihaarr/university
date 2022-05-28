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
    return ret;
}
btree* stack_top(btree_stack** top) {
    if(top == nullptr) return nullptr;
    return (*top)->node;
}
#endif //TEST_BTREE_STACK_HPP
