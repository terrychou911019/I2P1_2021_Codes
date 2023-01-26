#include <stdio.h>
int main()
{
    char x,y;
    int t;
    double a;
    scanf("%d %c %c",&t,&x,&y);
    if(x='C',y='F')
    {
        a=1.8*t+32;
        printf("%.2f\n",a);
    }
    else if(x='F',y='C')
    {
        a=(t-32)/1.8;
        printf("%.2f\n",a);
    }
    return 0;
}