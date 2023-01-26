#include <stdio.h>
#include <string.h>

char f0[2050], f1[2050];
long long int len[100];

char find(int n, long long int k) {
    if (n == 0) return f0[k];
    if (n == 1) return f1[k];
    if (k >= len[n - 2]) return find(n - 1, k - len[n - 2]);
    if (k < len[n - 2]) return find(n - 2, k);
}

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long int n, k;
        scanf("%s %s %lld %lld", f0, f1, &n, &k);
        len[0] = strlen(f0);
        len[1] = strlen(f1);
        for (int i = 2 ; i <= n ; i++) len[i] = len[i - 1] + len[i - 2];
        char ans = find(n, k);
        printf("%c\n", ans);
    }
    return 0;
}