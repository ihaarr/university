#include <iostream>

const int BUFF_SIZE = 256;
void f24(const char* file1, const char* file2);
char* del_str(char* str, const char* to_del);

int main()
{
    //setlocale(LC_ALL, "Russian");
    f24("test.txt", "output.txt");
    return 0;
}

int str_size(const char* str_begin, const char* str) {
    int i = 0;
    while (str != str_begin && !isspace(*str)) {
        str--;
        i++;
    }

    return i;
}

char* del_str(char* str, const char* to_del) {
    char* s = strstr(str, to_del);
    if (!s) {
        return str;
    }

    int before_size = str_size(str, s);
    long diff = s - str - before_size;
    int to_del_size = before_size + strlen(to_del);
    for (int i = 0; str[i + diff] != '\0'; i++) {
        str[diff + i] = str[diff + i + to_del_size];
    }

    return str;
}

char* replace(char* str, char* to, const int size) {
    char buff[BUFF_SIZE];
    int len = strlen(str);
    for(int i = 0; i < size; i++) {
        buff[i] = str[i];
        str[i] = to[i];
    }

    int j = to - str;
    for(int k = 0; k < size; k++, j++) {
        str[j] = buff[k];
    }

    return str;
}

char* to_begin(char* str) {
    int offset = 0;
    char* five = strstr(str + offset, "otl");
    while (five) {
        int size = str_size(str + offset, five);
        replace(str + offset, five - size, size + 3);
        offset += size + 3;
        five = strstr(str + offset, "otl");
    }

    return str;
}

char* to_del(char* str) {
    char* to_del = strstr(str, "neut");
    while (to_del) {
        del_str(str, "neut");
        to_del = strstr(str, "neut");
    }

    return str;
}

char* change_str(char* str) {
    to_del(str);
    to_begin(str);
    return str;
}

void f24(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "wb");
    char buff[BUFF_SIZE];
    while (fgets(buff, BUFF_SIZE, f1) != NULL) {
        fprintf(f2, "%s", change_str(buff));
    }

    fclose(f1);
    fclose(f2);
}
