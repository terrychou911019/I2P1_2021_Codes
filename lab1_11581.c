#include <stdio.h>
int main(void)
{
    int a,b,c,d;
    scanf("%d",&a);
    int A,B;
    A=a;
    b=A%10;
    c=A/10;
    B=1000*b+c;
    printf("%d",A+B);
    return 0;
}