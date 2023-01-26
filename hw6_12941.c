#include <stdio.h>
int main (){
    int n, m, t, x, k1, k2;
    scanf("%d %d %d", &n, &m, &t);
    int a[n + 2][m + 2];
    int b[n + 2][m + 2];
    for (int i1 = 1 ; i1 < n + 1 ; i1++){
        for (int i2 = 1 ; i2 < m + 1 ; i2++){
            scanf("%d", &x);
            a[i1][i2] = x;
            b[i1][i2] = a[i1][i2];
        }
    }
    for (int i3 = 0 ; i3 < m + 2 ; i3++){
        a[0][i3] = 2;
        b[0][i3] = 2;
    }
    for (int i4 = 0 ; i4 < m + 2 ; i4++){
        a[n + 1][i4] = 2;
        b[n + 1][i4] = 2;
    }
    for (int i5 = 1 ; i5 < n + 1 ; i5++){
        a[i5][0] = 2;
        b[i5][0] = 2;
    }
    for (int i6 = 1 ; i6 < n + 1 ; i6++){
        a[i6][m + 1] = 2;
        b[i6][m + 1] = 2;
    }
    for (int j = 0 ; j < t ; j++){
        k1 = 0, k2 = 0;
        for (int j1 = 1 ; j1 < n + 1 ; j1++){
            for (int j2 = 1 ; j2 < m + 1 ; j2++){
                k1 = 0, k2 = 0;
                if (a[j1][j2] == 1){
                    for (int j3 = j1 - 1 ; j3 < j1 + 2 ; j3++){
                        for (int j4  = j2 - 1 ; j4 < j2 + 2 ; j4++){
                            if (a[j3][j4] == 1) k1++;
                        }
                    }
                    k1 = k1 - 1;
                    if (k1 == 3 || k1 == 2) b[j1][j2] = 1;
                    else b[j1][j2] = 0;
                }
                if (a[j1][j2] == 0){
                    for (int j5 = j1 - 1 ; j5 < j1 + 2 ; j5++){
                        for (int j6 = j2 - 1 ; j6 < j2 + 2 ; j6++){
                            if (a[j5][j6] == 1) k2++;
                        }
                    }
                    if (k2 == 3) b[j1][j2] = 1;
                    else b[j1][j2] = 0;
                }
            }
        }
        for (int h1 = 1 ; h1 < n + 1 ; h1++){
            for (int h2 = 1 ; h2 < m + 1 ; h2++){
                a[h1][h2] = b[h1][h2];
            }
        }
    }
    for (int h3 = 1 ; h3 < n + 1 ; h3++){
        for (int h4 = 1 ; h4 < m + 1 ; h4++){
            if (h4 < m) printf("%d ", a[h3][h4]);
            else printf("%d\n", a[h3][h4]);
        }
    }
    return 0;
}