#include <stdio.h>
int main (){
    int t, a, b, temp;
    scanf("%d", &t);
    for (int i = 0 ; i < t ; i++){
        scanf("%d %d", &a, &b);
        while (b != 0){
            temp = a;
            a = b;
            b = temp % b;
        }
        printf("%d\n", a);
    }
    return 0;
}