#include <iostream>

const int BUFF_SIZE = 256;
int stringlen(const char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}

char *stringcat(char *str1, const char *str2)
{
    int i, j;
    for (i = 0; str1[i] != '\0'; i++);
    for (j = 0; str2[j] != '\0'; j++)
    {
        str1[i + j] = str2[j];
    }
    str1[i + j] = '\0';
    return str1;
}

char *stringcpy(const char *str1)
{
    int size = strlen(str1);
    char *str = new char[size + 1];
    for (int i = 0; str1[i] != '\0'; i++)
    {
        str[i] = str1[i];
    }
    str[size] = '\0';
    return str;
}

char *stringchar(const char *str, const char c)
{
    for (int i = 0; i < stringlen(str); i++)
    {
        if (str[i] == c)
        {
            return (char *)(str + i);
        }
    }

    return NULL;
}

int stringcmp(const char *str1, const char *str2)
{
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] < str2[i])
            return -1;
    }

    return 0;
}

char *stringstring(const char *str1, const char *str2)
{
    int str2_len;

    str2_len = stringlen(str2);
    while (*str1)
    {
        if (*str1 == *str2)
        {
            if (!strncmp(str1, str2, str2_len))
                return ((char *)str1);
        }
        str1++;
    }
    return NULL;
}

void f1(char* str) 
{
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Len = %d\n", stringlen(str));
}

void f2(char* str) 
{
    char str2[BUFF_SIZE];
    printf("Enter first string: ");
    scanf("%s", str);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("new str = %s\n", stringcat(str, str2));
}

void f3(char* str) 
{
    printf("Enter a string:");
    scanf("%s", str);
    char* str2 = stringcpy(str);
    printf("copy str = %s\n", str2);
    free(str2);
}

void f4(char* str) 
{
    char ch;
    printf("Enter a string:");
    scanf("%s", str);
    printf("Enter a char: ");
    scanf("%c", &ch);
    char* a = stringchar(str, ch);
    if(a) 
        printf("str = %s\n", a);
    else
        printf("no symbol\n");
}

void f5(char* str) 
{
    char str2[BUFF_SIZE];
    printf("Enter first string: ");
    scanf("%s", str);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("new str = %d\n", stringcmp(str, str2));
}

void f6(char* str) 
{
    char str2[BUFF_SIZE];
    printf("Enter first string: ");
    scanf("%s", str);
    printf("Enter sub string: ");
    scanf("%s", str2);
    char* sub = stringstring(str, str2);
    if(sub)
        printf("sub str = %s\n", sub);
    else
        printf("no sub string\n");
}

int main() 
{
    int n;
    char buff[BUFF_SIZE];
    bool isRunning = true;
    printf("1 - Длина строки\n");
    printf("2 - Конкатенация строк\n");
    printf("3 - Скопировать строку\n");
    printf("4 - Найти символ в строке\n");
    printf("5 - Сравнение строк\n");
    printf("6 - Найти подстроку в строке\n");
    printf("7 - Выйти\n");
    while(isRunning)
    {
        printf("Enter a num of menu: ");
        scanf("%d", &n);
        switch(n)
        {
            case 1: f1(buff); break;
            case 2: f2(buff); break;
            case 3: f3(buff); break;
            case 4: f4(buff); break;
            case 5: f5(buff); break;
            case 6: f6(buff); break;
            case 7: isRunning = false; break;
            default: printf("Wrong number. Retry\n");
        }
    }
    return 0;
}