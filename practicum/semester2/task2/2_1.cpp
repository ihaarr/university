#include <iostream>

/*
1.	Написать исполнительную систему «Функции работы со строками», 
которая включает в себя функции, имитирующие стандартные 
(strlen(), strcat(),  strcpy(),  strstr(),  strchr(),  strcmp()).
*/
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