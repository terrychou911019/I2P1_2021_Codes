#include <stdio.h>
#include <string.h>
int main (){
   char L[1001];
   scanf("%s", L);
   int a;
   int c;
   int b = strlen(L);
   char t;
   for (c = 1 ; c <= b ; c++){
       for (a = 1 ; a <= b - 1 ; a++){
            t = L[a - 1];
            L[a - 1] = L[a];
            L[a] = t; 
        }
       printf("%s\n", L);
   }
   return 0;
}