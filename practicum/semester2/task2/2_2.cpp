#include <iostream>

/*
На вход программы подается текст на английском языке. 
Требуется написать программу, которая будет определять и выводить на экран английскую букву, 
встречающуюся в этом тексте чаще всего, и количество таких букв. 
Строчные и прописные буквы при этом считаются не различимыми. 
Если искомых букв несколько, то программа должна выводить на экран первую из них по алфавиту
*/
int main()
{
    char str[256] = {};
    int chars[26] = {};
    int max_count = 0;
    char max_char;
    scanf("%255[^\n]", str);
    // 65  - A in ASCII
    // 90  - Z in ASCII
    // 97  - a in ASCII
    // 122 - z in ASCII
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            chars[str[i] - 65]++;
        else if (str[i] >= 97 && str[i] <= 122)
            chars[str[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (max_count < chars[i])
        {
            max_count = chars[i];
            max_char = i + 65;
        }
    }

    printf("%c %d\n", max_char, max_count);
    return 0;
}