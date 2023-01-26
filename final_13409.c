#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str[110], op[15], s[110];
int len[110], n, m, x, y, k;

void add(int x, char *s) {
    len[x] += strlen(s);
    char *tmp = (char *)malloc(sizeof(char) * (len[x] + 1));
    strcpy(tmp, str[x]);
    strcat(tmp, s);
    tmp[len[x]] = '\0';
    free(str[x]);
    str[x] = tmp;
}
void delete(int x, int k) {
    if (k > len[x]) {
        len[x] = 0;
        free(str[x]);
        str[x] = (char *)malloc(sizeof(char));
        str[x][0] = '\0';
    } else {
        len[x] -= k;
        char *tmp = (char *)malloc(sizeof(char) * (len[x] + 1));
        strncpy(tmp, str[x], len[x]);
        tmp[len[x]] = '\0';
        free(str[x]);
        str[x] = tmp;
    }
}
void swap(int x, int y) {
    char *tmp;
    int len_tmp;
    tmp = str[x];
    str[x] = str[y];
    str[y] = tmp;
    len_tmp = len[x];
    len[x] = len[y];
    len[y] = len_tmp;
}
void longest(int n) {
    int id = 1, max = len[1];
    for (int i = 1 ; i <= n ; i++) {
        if (max < len[i]) {
            max = len[i];
            id = i;
        }
    }
    printf("%d %s\n", max, str[id]);
}
void all(int n) {
    for (int i = 1 ; i <= n ; i++) {
        printf("%s\n", str[i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        str[i] = (char *)malloc(sizeof(char));
        str[i][0] = '\0';
    }
    for (int i = 0 ; i < m ; i++) {
        scanf("%s", op);
        if (op[0] == 'a' && op[1] == 'd') {
            scanf("%d %s", &x, s);
            add(x, s);
        }
        else if (op[0] == 'd') {
            scanf("%d %d", &x, &k);
            delete(x, k);
        }
        else if (op[0] == 's') {
            scanf("%d %d", &x, &y);
            swap(x, y);
        }
        else if (op[0] == 'l') {
            longest(n);
        }
        else if (op[0] == 'a' && op[1] == 'l') {
            all(n);
        }
    }
    return 0;
}