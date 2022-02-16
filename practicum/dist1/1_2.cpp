#include <iostream>

const int N = 20;
bool isSimple(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}
int main()
{
    for (int i = N - 1; i > 0; i--)
    {
        if (isSimple(i))
        {
            for (int j = 1; j < i; j++)
            {
                if (isSimple(j))
                {
                    if (i + j == N)
                        printf("%d + %d\n", i, j);
                }
            }
        }
    }
    return 0;
}