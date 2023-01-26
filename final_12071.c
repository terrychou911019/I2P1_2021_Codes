#include <stdio.h>
#include <limits.h>

int n, visited_cnt, distance, matrix[10][10], visited[10], MIN = INT_MAX;

void dfs(int cur) {
    if (visited_cnt == n) {
        if (distance + matrix[cur][0] < MIN) {
            MIN = distance + matrix[cur][0];
        }
    } else {
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                visited_cnt++;
                distance += matrix[cur][i];
                dfs(i);
                visited[i] = 0;
                visited_cnt--;
                distance -= matrix[cur][i];
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    visited[0] = 1;
    visited_cnt = 1;
    dfs(0);
    printf("%d\n", MIN);
    return 0;
}