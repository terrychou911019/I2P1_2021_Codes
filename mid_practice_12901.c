#include <stdio.h>
int x[100000], y[100000];
int ans[101][101];
int main () {
    for (int i3 = 0 ; i3 < 101 ; i3++) {
        for (int i4 = 0 ; i4 < i3 + 1 ; i4++) {
            if (i4 == 0 || i3 == i4) ans[i3][i4] = 1;
            else ans[i3][i4] = (ans[i3 - 1][i4 - 1] + ans[i3 - 1][i4]) % 10007;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i1 = 0 ; i1 < n ; i1++) {
        scanf("%d", &(x[i1]));
    }
    for (int i2 = 0 ; i2 < n ; i2++) {
        scanf("%d", &(y[i2]));
    }
    int practices = 1;
    for (int j = 0 ; j < n ; j++) {
        practices = (practices * ans[x[j]][y[j]]) % 10007;
    }
    printf("%d\n", practices);
    return 0;
}