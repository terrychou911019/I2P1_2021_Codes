#include <stdio.h>
int main (){
    int n, m, q, t, a, b, x;
    scanf("%d %d %d", &n, &m, &q);
    int num[n], seat[n];
    for (int i = 0 ; i < n ; i++) seat[i] = i + 1;
    for (int j = 0 ; j < m ; j++){
        scanf("%d %d", &a, &b);
        t = seat[a - 1];
        seat[a - 1] = seat[b - 1];
        seat[b - 1] = t;
    }
    for (int k = 0 ; k < n ; k++) num[seat[k] - 1] = k + 1;
    for (int l = 0 ; l < q ; l++){
        scanf("%d", &x);
        if (l < q - 1) printf("%d ", num[x - 1]);
        else printf("%d\n", num[x - 1]);
    }
    return 0;
}