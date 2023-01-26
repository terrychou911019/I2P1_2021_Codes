#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef long long ll;

ll* matrix_pow(ll *A, ll b, ll m);

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);     // Get n and m
    ll A[4];
    A[0] = 1; A[1] = 1;
    A[2] = 1; A[3] = 0;             // Define what matrix A is
    ll *An = matrix_pow(A, n, m);   // Calculate A^n
    printf("%lld\n", An[2]);        // Fn = An[2][1]*F1 + An[2][2]*F0 = An[2][1] (F0=0, F1=1)
    return 0;
}

void cal (ll* ans, ll* x, ll* y, ll m);

ll* matrix_pow(ll *A, ll b, ll m) {
    ll* ans = (ll *)malloc(sizeof(ll) * 4);
    ll temp[4];
    if (b == 0) {
        ans[0] = 1;
        ans[1] = 0;
        ans[2] = 0;
        ans[3] = 1;
        return ans;
    }
    ll* t = matrix_pow(A, b / 2, m);
    if (b % 2 == 0) {
        cal(ans, t, t, m);
    } else {
        cal(ans, t, t, m);
        cal(temp, ans, A, m);
        for (int i = 0 ; i < 4 ; i++) ans[i] = temp[i];
    } 
    free(t);
    return ans;
}

void cal (ll* ans, ll* x, ll* y, ll m) {
    ans[0] = (x[0] * y[0] + x[1] * y[2]) % m;
    ans[1] = (x[0] * y[1] + x[1] * y[3]) % m;
    ans[2] = (x[2] * y[0] + x[3] * y[2]) % m;
    ans[3] = (x[2] * y[1] + x[3] * y[3]) % m;
}