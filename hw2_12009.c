#include <stdio.h>
int main()
{
    char a,b,c;
    long n,x,y,z;
    scanf("%c%c%c %ld",&a,&b,&c,&n);
    x=a+n;
    y=b+n;
    z=c+n;
    if(x>'Z')
    {
        x='A'+(x-'A')%26;
    }
    if(y>'Z')
    {
        y='A'+(y-'A')%26;
    }
    if(z>'Z')
    {
        z='A'+(z-'A')%26;
    }
    if(x<'A')
    {
        x='Z'-('Z'-x)%26;
    }
    if(y<'A')
    {
        y='Z'-('Z'-y)%26;
    }
    if(z<'A')
    {
        z='Z'-('Z'-z)%26;
    }
    printf("%c%c%c\n",x,y,z);
    return 0;
}