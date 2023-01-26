#include <stdio.h>
long long int x[1000001];
int main (){
    int n, m, a, l ,r;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &a);
        x[i + 1] = x[i] + a;
    }
    scanf("%d", &m);
    for (int j = 0 ; j < m ; j++){
        scanf("%d %d", &l, &r);
        printf("%lld\n", x[r] - x[l - 1]);
    }
    return 0;
}