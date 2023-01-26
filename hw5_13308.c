#include <stdio.h>
int main () {
    int i, j, sum;
    char input;
    char x[100] = {};
    while (1) {
        for (i = 0 ; i <= 99 ; i++) {
            scanf("%c", &input);
            if (input == '\n')break;
            x[i] = input;
        }
        if (i == 1 && x[0] == '0')break;
        for (sum = 0, j = 0 ; j < i ; j++) {
            if ('a' <= x[j] && x[j] <= 'z') {
                sum += (x[j] - 96);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}