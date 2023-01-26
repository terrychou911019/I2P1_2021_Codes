#include <stdio.h>

int main()
{
   int m,n;
   scanf("%d %d",&m,&n);
   if(m*n%2==1)
   {
       printf("%d",m*n/2+1);
   }
   else printf("%d",m*n/2);

   return 0;
    
}