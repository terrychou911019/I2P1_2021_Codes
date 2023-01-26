#include <stdio.h>
int main ()
{
    unsigned int a, b, c, x;
    scanf("%u", &a);
    c = a;
    b = 0;
    while ( a != 0 )
    {  
        x = a % 10;
        b = 10 * b + x;
        a = a / 10;
    }
    printf("%u\n", c + b);
    return 0;
}