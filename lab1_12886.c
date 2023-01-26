#include <stdio.h>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d,%d,%d\n",&a,&b,&c);
    scanf("%d,%d,%d\n",&d,&e,&f);
    printf("%d\n",1000000*a+1000*b+c+1000000*d+1000*e+f);
    return 0;
}