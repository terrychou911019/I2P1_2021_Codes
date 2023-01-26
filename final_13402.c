#include <stdio.h>

int t, n, m, b[20][20];
char matrix[20][20];

int bit_cnt(int i) {
    int cnt = 0;
    for ( ; i ; i >>= 1) {
        if (i & 1) cnt++;
    }
    return cnt;
}
int check() {
    int add = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            add += b[i][j];
        }
    }
    if (add == 0 || add == n * m) return 1;
    else return 0;
}
void flip(int x, int y) {
    b[x][y] ^= 1;
    b[x + 1][y] ^= 1;
    b[x - 1][y] ^= 1;
    b[x][y + 1] ^= 1;
    b[x][y - 1] ^= 1;
}
void flip_all(int bb) {
    for (int i = 0 ; i < n * m ; i++) {
        if (bb & (1 << i)) flip(i / m + 1, i % m + 1);
    }
}
void solve() {
    int bb, min = 100000;
    for (bb = 0 ; bb < (1 << (n * m)) ; bb++) {
        flip_all(bb);
        int b_cnt = bit_cnt(bb);
        if (check() && b_cnt < min) min = b_cnt;
        flip_all(bb); //restore
    }
    if (min == 100000) printf("oops\n");
    else printf("%d\n", min);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                scanf(" %c", &matrix[i][j]);
                if (matrix[i][j] == 'w') b[i][j] = 1;
                else b[i][j] = 0;
            }
        }
        solve();
    }
    return 0;
}