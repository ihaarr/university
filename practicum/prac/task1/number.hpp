#ifndef TEST_NUMBER_HPP
#define TEST_NUMBER_HPP

struct number {
    int inf1;
    int inf2;
    number* ptr;
};

number* stack_add(number* top, int inf1, int inf2) {
    number* new_top = new number;
    new_top->inf1 = inf1;
    new_top->inf2 = inf2;
    new_top->ptr = top;
    return new_top;
}
number* stack_pop(number* top, number*& poped) {
    poped = top;
    return top->ptr;
}
number* list_insert_to_begin(number* first, int inf1, int inf2) {
    number* el = new number;
    el->inf1 = inf1;
    el->inf2 = inf2;
    el->ptr = first;
    return el;
}
void list_print(number* first) {
    if(first->inf2 == '-') printf("%c", first->inf2);
    first = first->ptr;
    while(first != nullptr) {
        if(first->inf2 == -1) {
            if(first->inf1 != 0)
                printf("%d", first->inf1);
        }
        else printf("%d%d", first->inf1, first->inf2);
        first = first->ptr;
    }
    putchar('\n');
}

#endif //TEST_NUMBER_HPP
