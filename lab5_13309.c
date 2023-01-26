#include <stdio.h>
int num[256];
int main()
{
    int i, j, sum;
    char input, c[27];
    char x[100] = {};
    scanf("%s", c);
    for (int i1 = 0; i1 < 27; i1++)
    {
        num[c[i1]] = i1 + 1;
    }
    getchar();
    while (1)
    {
        for (i = 0; i <= 99; i++)
        {
            scanf("%c", &input);
            if (input == '\n')
                break;
            x[i] = input;
        }
        if ((i == 1 && x[0] == '0') || (i == 3 && x[0] == 'e' && x[1] == 'n' && x[2] == 'd'))
            break;
        for (j = 0, sum = 0; j < i; j++)
        {
            sum += num[x[j]];
        }
        printf("%d\n", sum);
    }
    return 0;
}