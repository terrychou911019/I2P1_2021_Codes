#include <stdio.h>
#include <string.h>
int main (){
    int t;
    char a[1001] = {}, b[1001] = {};
    scanf("%d", &t);
    for (int i1 = 0 ; i1 < t ; i1++){
        scanf("%s %s", a, b);
        int len_a = strlen(a), len_b = strlen(b), k = 0, flag = 0;
        for (int i2 = 0 ; i2 < len_a ; i2++){
            if(!flag){
                if (b[0] == a[i2]){
                    for (int i3 = i2, i4 = 0 ; i3 < len_a ; i3++, i4++){
                        if (a[i3] == b[i4]){
                            k++;
                            if (i3 == len_a - 1) flag = 1;
                        }
                        else{
                            k = 0;
                            break;
                        }
                    }
                }
            }
        }
        printf("%s", a);
        for (int j = k ; j < len_b ; j++){
            printf("%c", b[j]);
        }
        printf("\n");
    }
    return 0;
}