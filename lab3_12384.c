#include <stdio.h>
int main (){
    int a, b;
    long long int c;
    scanf("%d %d", &a, &b);
    c = 0;
    int i = 1;
    long long int x[16];
    int p = 0;
    while (i <= b){
        c = c * 10 + a;
        x[p] = c;
        i = i + 1;
        p = p + 1;
    }
    long long int sum = 0;
    int r = 0;
    while (r <= b - 1){
        sum = sum + x[r];
        r = r + 1;
    }
    printf("%lld\n", sum);
    return 0;
}