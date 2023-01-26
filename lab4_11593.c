#include <stdio.h>
int main () {
    int T;
    scanf("%d", &T);
    int n, m, t, a, b;
    for (a = 1 ; a <= T ; a++){
        scanf("%d %d %d", &n, &m, &t);
        for (b = 1 ; b <= n ; b++){
            if (b < n){
                if (t - m + 1 <= b && b <= t){
                    printf("^");
                }
                else {
                    printf("-");
                }
            }
            else {
                if (t - m + 1 <= b && b <=t){
                    printf("^\n");
                }
                else {
                    printf("-\n");
                }
            }
        }
    }
    return 0;
}