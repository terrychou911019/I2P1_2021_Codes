#include <stdio.h>
int main(){
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int a, b, x;
    int A[m][n];
    for (a = 0 ; a <= m - 1 ; a++){
        for (b = 0 ; b <= n - 1 ; b++){
            scanf("%d", &x);
            A[a][b] = x;
        }
    }
    int c, y1, y2, y3;
    int e, f, t;
    for (c = 1 ; c <= k ; c++){
        scanf("%d %d %d", &y1, &y2, &y3);
            if (y1 == 0){
                for (e = 0 ; e <= n - 1 ; e++){
                    t = A[y2][e];
                    A[y2][e] = A[y3][e];
                    A[y3][e] = t; 
                }
            }
            else if (y1 == 1){
                for (f = 0 ; f <= n - 1 ; f++){
                    A[y2][f] = A[y2][f] + A[y3][f];
                }
            }
        
    }
    int g, h, g1;
    int r[m];
    for (g1 = 0 ; g1 <= m - 1 ; g1++){
        r[g1] = 0;
    }
    for (g = 0 ; g <= m - 1 ; g++){
        for (h = 0 ; h <= n - 1 ; h++){
            r[g] = r[g] + A[g][h] * A[g][h];
        }
    }
    int i, j = 0;
    for (i = 0 ; i <= m - 2 ; i++){
        if (r[i + 1] > r[j]){
            j = i + 1;
        }
    }
    int p, q;
    q = 1;
    if (q = 1){
        for (p = 0 ; p <= n - 1 ; p++){
            if (p < n - 1){
                printf("%d ", A[j][p]);
            }
            else{
            printf("%d\n", A[j][p]);
            }
        }
        q = 0;
    }
    return 0;
}