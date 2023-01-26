#include <stdio.h>
int main () {
    int N;
    scanf("%d", &N);
    int a, b, x[N][N], y[N];
    for (a = 1 ; a <= N ; a++){
        scanf("%d", &b);
        x[a - 1][0] = b;
        y[a - 1] = b;
    }
    int c, d;
    for (c = 0 ; c <= N - 1 ; c++){
        for (d = 0 ; d <= N - 1 ; d++){
            if (d + 1 > N - 1){
                x[d + 1 - N][c + 1] = x[d][c];
            }
            else{
                x[d + 1][c + 1] = x[d][c];
            }
        }
    }
    int g;
    for (g = 0 ; g <= N - 1 ; g++){
        x[g][0] = y[g];
    }
    int e, f;
    for (e = 0 ; e <= N - 1 ; e++){
        for (f = 0 ; f <= N - 1 ; f++){
            if (f < N - 1){
                printf("%2d", x[e][f]);
            }
            else {
                printf("%2d\n", x[e][f]);
            }
        }
    }
    return 0;
}