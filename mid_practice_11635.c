#include <stdio.h>
#include <string.h>
char str[1000001];
int main () {
    scanf("%s", str);
    int len = strlen(str);
    for (char ch = 'A' ; ch <= 'z' ; ch++){
        int flag = 0;
        for (int i = 0 ; i < len ; i++){
           if (str[i] == ch){
               if (!flag){
                   printf("%c: %d", ch, i);
                   flag = 1;
               }
               else{
                   printf(" %d", i);
               }
           }
        }
        if (flag == 1){
            printf("\n");
        }
    }
    return 0;
}