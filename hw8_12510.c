#include <stdio.h>

char maze[1010][1010];
int walked[1010][1010], t, n, m, dir_x[4] = {1, -1, 0, 0}, dir_y[4] = {0, 0, 1, -1}, can_teleport;

void walk (int x, int y);
void teleport ();

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                scanf(" %c", &maze[i][j]);
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                walked[i][j] = 0;
            }
        }
        can_teleport = 0;
        walk(1, 1);
        teleport();
        if (walked[n][m]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

void walk (int x, int y) {
    int new_x, new_y;
    if (maze[x][y] == 'T') can_teleport = 1;
    walked[x][y] = 1;
    for (int i = 0 ; i < 4 ; i++) {
        new_x = x + dir_x[i];
        new_y = y + dir_y[i];
        if (new_x < 1 || new_y < 1 || new_x > n || new_y > m) continue;
        if (maze[new_x][new_y] == '#' || walked[new_x][new_y]) continue;
        walk(new_x, new_y);
    }
}
void teleport () {
    if (can_teleport) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if (maze[i][j] == 'T') walk(i, j);
            }
        }
    }
}