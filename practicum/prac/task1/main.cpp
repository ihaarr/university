#include <iostream>
#include "number.hpp"
/*
Получить  сумму  двух  целых  чисел.  Числа представлены  в  виде  двух  стеков   (информационная  часть  всех  элементов  кроме  вершины  - две  цифры  числа - тип  integer,  информационная  часть  вершины  -  знак  числа  и  количество  цифр  в  числе).  Результат  представлен  линейным  односвязным  списком,  информационная  часть  элементов  которого  такая  же,  как  у  элементов  стека. 
*/
number* diff_numbers(number* num1 , number* num2);
number* parse_number(const char* str) {
    char sign;
    int inf1, inf2;
    int count = 0;
    int i = 0;
    int len = strlen(str);
    number* top = nullptr;
    if(str[0] == '-') {
        sign = '-';
        i++;
    }
    else if(str[0] == '+') {
        sign = '+';
        i++;
    } else {
        sign = '+';
    }
    if((len - i) % 2 != 0) {
        top = stack_add(top, str[i] - '0', -1);
        i++;
    }
    for(; i < len; i += 2) {
        top = stack_add(top, str[i] - '0', str[i + 1] - '0');
    }

    if(sign == '-') top = stack_add(top, len - 1, sign);
    else top = stack_add(top, len, sign);
    return top;
}
//len(num1) > len(num2)
number* sum_numbers(number* num1  , number* num2) {
    int transfer = 0;
    int count = 0;
    int d1, d2;
    number* n1;
    number* n2;
    number* list = nullptr;
    while(num2 != nullptr) {
        num1 = stack_pop(num1, n1);
        num2 = stack_pop(num2, n2);
        if(n1->inf2 == -1 && n2->inf2 == -1) {
            d2 = -1;
            d1 = n1->inf1 + n2->inf1 + transfer;
        }
        else if(n1->inf2 == -1) {
            d2 = n2->inf2 + transfer;
            d1 = n1->inf1 + n2->inf1 + transfer;
        }
        else if(n2->inf2 == -1) {
            d1 = n1->inf1;
            d2 = n1->inf2 + n2->inf1 + transfer;
        }
        else {
            d2 = n1->inf2 + n2->inf2 + transfer;
            d1 = n1->inf1 + n2->inf1 + d2 / 10;
        }
        if(d2 != -1) {
            if (d2 > 9) {
                transfer = 1;
                d2 = d2 - 10;
            }
            else transfer = 0;
            count++;
        }
        if(d1 > 9) {
            transfer = 1;
            d1 = d1 - 10;
        }
        else transfer = 0;
        list = list_insert_to_begin(list, d1, d2);
        count++;
    }
    if(transfer != 0) {
        if(num1 == nullptr) {
            list = list_insert_to_begin(list, transfer, -1);
        } else {
            num1 = stack_pop(num1, n1);
            if(n1->inf2 == -1) d2 = -1;
            else d2 = n1->inf2 + transfer;
            if (d2 > 9) {
                transfer = 1;
                d2 = d2 - 10;
            }
            else transfer = 0;
            d1 = n1->inf1 + transfer;
            list = list_insert_to_begin(list, d1, d2);
        }
    }
    while(num1 != nullptr) {
        num1 = stack_pop(num1, n1);
        if(n1->inf2 != -1) count++;
        list = list_insert_to_begin(list, n1->inf1, n1->inf2);
        count++;
    }
    list = list_insert_to_begin(list, count, '+');
    return list;
}
number* sum_as_list(number* num1 , number* num2) {
    number* n1;
    number* n2;
    number* ret;
    num1 = stack_pop(num1, n1);
    num2 = stack_pop(num2, n2);
    if(n1->inf2 == '-') {
        if(n2->inf2 == '-') {
            if(n1->inf1 > n2->inf1) ret = diff_numbers(num1, num2);
            else ret = diff_numbers(num2, num1);
            ret->inf2 = '-';
            return ret;
        } else {
            if(n1->inf1 > n2->inf1) {
                return diff_numbers(num1, num2);
            } else {
                return diff_numbers(num2, num1);
            }
        }
    } else {
        if(n2->inf2 == '-') {
            if(n1->inf1 > n2->inf1) {
                ret = diff_numbers(num1, num2);
                ret->inf2 = '+';
                return ret;
            }
            else {
                return diff_numbers(num2, num1);
            }
        } else {
            if(n1->inf1 > n2->inf1) return sum_numbers(num1, num2);
            else return sum_numbers(num2, num1);
        }
    }
}
number* diff_numbers(number* num1 , number* num2) {
    int transfer = 0;
    int count = 0;
    int d1, d2;
    number* n1;
    number* n2;
    number* list = nullptr;
    while(num2 != nullptr) {
        num1 = stack_pop(num1, n1);
        num2 = stack_pop(num2, n2);
        if(n1->inf2 == -1 && n2->inf2 == -1) {
            d2 = -1;
            d1 = n1->inf1 - n2->inf1 - transfer;
            list = list_insert_to_begin(list, d1, d2);
            count++;
            continue;
        }
        else if(n1->inf2 == -1) {
            d2 = n2->inf2 - transfer;
            d1 = n1->inf1 - n2->inf1 - transfer;
        }
        else if(n2->inf2 == -1) {
            d1 = n1->inf1;
            d2 = n1->inf2 - n2->inf1 - transfer;
        }
        else {
            d2 = n1->inf2 - n2->inf2 - transfer;
            d1 = n1->inf1 - n2->inf1 - d2 / 10;
        }
        if(d2 < 0) {
            d1 -= 1;
            d2 += 10;
        }
        if(d1 < 0) {
            d1 += 10;
            transfer = 1;
        } else {
            transfer = 0;
        }
        list = list_insert_to_begin(list, d1, d2);
        count += 2;
    }
    if(d1 < 0) {
        list->inf1 = abs(d1 + 1);
        list = list_insert_to_begin(list, count, '-');
        return list;
    }
    if(transfer == 1) {
        if(num1 == nullptr) {
            list = list_insert_to_begin(list, transfer, -1);
        } else {
            num1 = stack_pop(num1, n1);
            if(n1->inf2 == -1) d2 = -1;
            else {
                d2 = n2->inf2 - transfer;
                if (d2 < 0) {
                    transfer = 1;
                    d2 = d2 + 10;
                } else {
                    transfer = 0;
                }
            }
            d1 = n1->inf1 - transfer;
            list = list_insert_to_begin(list, d1, d2);
        }
    }
    while(num1 != nullptr) {
        num1 = stack_pop(num1, n1);
        if(n1->inf2 != -1) count++;
        list = list_insert_to_begin(list, n1->inf1, n1->inf2);
        count++;
    }
    list = list_insert_to_begin(list, count, '-');
    return list;
}
int main() {
    number* n1 = parse_number("-155");
    number* n2 = parse_number("2055");
    number* a = sum_as_list(n1, n2);
    list_print(a);
    return 0;
}
