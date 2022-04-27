#include <iostream>
#include <cstring>

//Удалить из строки  слова четной длины и перевернуть слова нечетной длины.
const size_t str_SIZE = 256;
size_t mystrlen(const char* str) {
    size_t len = 0;
    for(; str[len] != '\0' && str[len] != ' '; len++);
    return len;
}
bool is_str_even(const char* str) {
    return !(mystrlen(str) % 2);
}
//ASDASDASD
char* strdel(char* str, size_t k, size_t m) {
    size_t len = strlen(str + k + m + 1);
    size_t i = 0;
    if(len == 0) (str + k)[i] = '\0';
    else {
        for (; i < len + 1; i++)
            (str + k)[i] = (str + k + m + 1)[i];
        (str + k)[i] = '\0';
    }
    return str;
}
char* rotate_str(char* str, size_t offset, size_t size) {
    char ch;
    for(size_t i = 0; i < size / 2; i++) {
        ch = (str + offset)[i];
        (str + offset)[i] = (str + offset)[size - i - 1];
        (str + offset)[size - i - 1] = ch;
    }
    return str;
}
int main() {
    char str[str_SIZE];
    printf("Enter a text: ");
    gets(str);
    size_t offset = 0;
    size_t len;
    while(str[offset] != '\0') {
        len = mystrlen(str + offset);
        if(is_str_even(str + offset)) {
            if(*(str + offset + len + 1) == '\0') strdel(str, offset, len);
            else strdel(str, offset, len);
        } else {
            rotate_str(str, offset, len);
            if(*(str + offset + len) == '\0') offset += len;
            else offset += len + 1;
        }
    }
    printf("%s\n", str);
    return 0;
}