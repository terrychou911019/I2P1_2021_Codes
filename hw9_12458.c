#include <stdio.h>

int n, k, dp[1005][1005];
char str[1005];

int pal (int l, int r); //number of palindrome digits 
int max (int a, int b);

int main () {
    scanf("%d %d", &n, &k);
    scanf(" %s", str);
    if (k >= n - pal(0, n - 1)) printf("Yes\n");
    else printf("No\n");
    return 0;
}

int pal (int l, int r) {
    if (dp[l][r] != 0) return dp[l][r];
    if (l > r) return dp[l][r] = 0;
    if (l == r) return dp[l][r] = 1;
    if (str[l] == str[r]) return dp[l][r] = pal(l + 1, r - 1) + 2;
    if (str[l] != str[r]) return dp[l][r] = max(pal(l + 1, r), pal(l, r - 1));
}

int max (int a, int b) {
    if (a > b) return a;
    else return b;
}