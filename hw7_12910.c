#include <stdio.h>
int n, m, flag;
char tetris[50][50];
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            scanf(" %c", &tetris[i][j]);
        }
    }

    while (1) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if(tetris[i][j] == 'o' && (i == n || tetris[i+1][j] =='x')) flag = 1;
            }
        }
        if(flag) break;
        for (int i = n ; i >= 1 ; i--) {
            for (int j = 1 ; j <= m ; j++) {
                if(tetris[i][j]=='o') tetris[i+1][j] = 'o', tetris[i][j] = '.';
            }
        }
    }

    for (int i = n ; i >= 1 ; i--) {
        flag = 0;
        for (int j = 1 ; j <= m ; j++) {
            if (tetris[i][j] == '.') flag = 1;
            else if (tetris[i][j] == 'o') tetris[i][j] ='x';
        }
        if (!flag) {
            for (int k = i ; k >= 1 ; k--) {
                for (int j = 1 ; j <= m ; j++) {
                    tetris[k][j] = tetris[k - 1][j];
                }
            }
            for (int j = 1 ; j <= m ; j++) tetris[1][j] = '.';
            i++;
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            printf("%c", tetris[i][j]);
        }
        printf("\n");
    }
    return 0;
}