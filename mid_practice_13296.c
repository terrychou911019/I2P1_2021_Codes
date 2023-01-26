#include <stdio.h>
void move ();
char floor[2505][2505];
int direct[4][2] = {{1 , 0}, {0, -1}, {-1, 0}, {0, 1}};
int n, m, x, y, d, steps, new_x, new_y;

int main () {
    scanf("%d %d", &n, &m);
    d = 0;
    x = -1;
    y = m - 1;
    for (steps = (n * m + 1) / 2 ; steps > 0 ; steps--) {
        move ();
        printf("%d %d\n", x, y);
        move ();
    }
    return 0;
}

void move () {
    new_x = x + direct[d][0];
    new_y = y + direct[d][1];
    if (new_x < 0 || new_x > n - 1 || new_y < 0 || new_y > m - 1 || floor[new_x][new_y] != '\0') {
        d = (d + 1) % 4;
        new_x = x + direct[d][0];
        new_y = y + direct[d][1];
    }
    x = new_x;
    y = new_y;
    floor[x][y] = 'm';
}