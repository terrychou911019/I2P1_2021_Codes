#include <stdio.h>
int main (){
    int n, m;
    int k = 0;
    char a[1001], b[1001];

    while (scanf("%d %d", &n, &m) != EOF){
        scanf("%s %s", a, b);
        if (n == m){
            for (int i = 0 ; i <= n - 1 ; i++){
                for (int j = 0 ; j <= n - 1 ; j++){
                    if (b[i] == a[j]){
                        k = k + 1;
                        a[j] = 0;
                        break;
                    }
                }
            }
            if (k == n){
                printf("YES\n");
                k = 0;
            }
            else{
                printf("NO\n");
                k = 0;
            }
        }
        else if (n != m){
            printf("NO\n");
        }
    }

    return 0;
}