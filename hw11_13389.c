#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char str[10], buf[105][7], output[105][7], *p[105];

void bubble(char str[]);
void order();
//int cmp();

int main() {
    scanf("%d", &n);
    for (int k = 0 ; k < n ; k++) {
        scanf("%s", str);
        bubble(str);
        for (int i = 0 ; i < 6 ; i++) {
            buf[k][i] = str[i];
        }
    }
    for (int i = 0 ; i < n ; i++) p[i] = &buf[i][0];
    //qsort(buf, n, sizeof(buf[0]), cmp);
    order();
    for (int i = 0 ; i < n ; i++) {
        if (i < n - 1) printf("%s ", p[i]);
        else printf("%s\n", p[i]);
    }
    return 0;
}

/*int cmp(char *a, char*b) {
    return strcmp(a, b);
}*/

void order() {
    char *temp;
    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = 0 ; j < n - 1 - i ; j++) {
            if (strcmp(p[j], p[j + 1]) > 0) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void bubble(char str[]) {
    char temp;
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 - i ; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}