#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main () {
    char x[1505], ch;
    int i = 0, len, sum = 0, n = 1;
    while (1) {
        scanf("%c", &x[i]);
        if (x[0] == '0' && x[1] == '\n') break;
        else if (x[i] == '\n') {
            len = strlen(x);
            n = 1;
            for (int j = 0 ; j < len ; j++) {
                if (isdigit(x[len - 1 - j])) {
                    sum += (x[len - 1 -j] - 48) * n;
                    n *= 10;
                }
                else n = 1;
            }
            printf("%d\n", sum);
            sum = 0;
            for (int j = 0 ; j < len ; j++) {
                x[j] = '\0';
            }
            i = 0;
            continue;
        }
        i++;
    }
    return 0;
}