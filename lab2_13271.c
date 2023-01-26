#include <stdio.h>
int main()
{
    double a,b,c,d,e;
    scanf("%lf %lf %lf",&a,&b,&c);
    scanf("%lf %lf",&d,&e);
    if(d==0)
    {
        printf("%.3f\n",(a*e/b)+c);
    }
    else if(d=!0)
    {
        printf("%.3f\n",(e-c)*b/a);
    }
    return 0;
}