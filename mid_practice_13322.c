#include <stdio.h>

int a[200000];

int main () {
    int n, sum = 0, max_sum = 0;

    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        sum += a[i];
        if (sum > max_sum) max_sum = sum;
        if (sum < 0) sum = 0;
    }
    printf("%d\n", max_sum);
    
    return 0;
}