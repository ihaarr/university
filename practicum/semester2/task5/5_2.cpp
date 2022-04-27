#include <iostream>
#include <cstring>

const size_t MAX_BUFF_SIZE = 256;

/*
На вход программе подается строка (длиной не более 250 символов), в которой нужно зашифровать все английские слова (словом называется непрерывная последовательность английских букв, слова друга от друга отделяются любыми другими символами, длина слова не превышает 15 символов).  Каждое слово зашифровано с помощью циклического сдвига на длину этого слова. Например, если длина слова равна K, каждая буква в слове заменяется на букву, стоящую в английском алфавите на K букв дальше (алфавит считается циклическим, то есть, за буквой Z стоит буква A). Строчные буквы при этом остаются строчными, а прописные – прописными. Символы, не являющиеся английскими буквами, не изменяются.
Требуется написать программу, которая будет выводить на экран текст зашифрованного сообщения. Например, если исходный текст был таким:
Day, mice. "Year" is a mistake. 
то результат шифровки должен быть следующий:
Gdb, qmgi. "Ciev" ku b tpzahrl.

*/
void shift_word(char* str, size_t len) {
    for(size_t i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] += len % 26;
            if (str[i] > 'z')
                str[i] -= 26;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += len % 26;
            if (str[i] > 'Z')
                str[i] -= 26;
        }
    }
}
size_t get_len_of_word(const char* str) {
    size_t len = 0;
    for(; str[len] != ' ' && str[len] != '\0'; len++);
    return len;
}
int main() {
    size_t offset = 0;
    size_t len_of_word = 0;
    char str[MAX_BUFF_SIZE];
    gets(str);
    while(str[offset] != '\0') {
        if(isspace(*(str + offset))) {
            offset++;
            continue;
        }
        if(isalnum(*(str + offset))) {
            len_of_word = get_len_of_word(str + offset);
            shift_word(str + offset, len_of_word);
            offset += len_of_word;
        }
    }
    printf("%s\n", str);
    return 0;
}