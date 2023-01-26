#include <stdio.h>
#include <math.h>

int n, s, t, height[20], color[20], stone[20], max_energy, max_jumps;

void jumping (int cur_position, int cur_energy, int jumps);

int main () {
    scanf("%d %d %d", &n, &s, &t);
    for (int i = 1 ; i <= n ; i++) scanf("%d", &height[i]);
    for (int i = 1 ; i <= n ; i++) scanf("%d", &color[i]);
    jumping(s, 0, 0);
    printf("%d %d\n", max_energy, max_jumps);
    return 0;
}

void jumping (int cur_position, int cur_energy, int jumps) {
    if (cur_position == t) {
        if (cur_energy >= max_energy) {
            max_energy = cur_energy;
            max_jumps = jumps;
        }
        else if (cur_energy == max_energy && jumps > max_jumps) max_jumps = jumps;
    }
    stone[cur_position] = 1; //標記踩過的石頭
    for (int i = 1 ; i <= n ; i++) {
        if (stone[i] == 0 && (abs(i - cur_position) == 1 || color[i] == color[cur_position])) {
            jumping(i, cur_energy + abs(i - cur_position) * abs(height[i] - height[cur_position]), jumps + 1);
        }
    }   
    stone[cur_position] = 0;
}