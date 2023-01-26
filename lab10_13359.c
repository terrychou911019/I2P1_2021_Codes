#include <stdio.h>

int t, n, a, b, ma, mb, pooh_record[100005], piglet_record[100005], k[100005], l[100005];
char player[10], ch;

int pooh_turn (int n);
int piglet_turn (int n);

int main () {
    scanf("%d", &t);
    while (t--) {
        for (int i = 1 ; i <= 100000 ; i++) pooh_record[i] = 2;
        for (int i = 1 ; i <= 100000 ; i++) piglet_record[i] = 2;
        scanf("%d %d %d %d %d", &n, &a, &b, &ma, &mb);
        scanf(" %s", player);
        for (int i = 0 ; i < ma ; i++) {
            scanf("%d", &k[i]);
            pooh_record[k[i]] = 1;
        }
        for (int i = 0 ; i < mb ; i++) {
            scanf("%d", &l[i]);
            piglet_record[l[i]] = 1;
        }
        if (player[1] == 'o') {
            if (pooh_turn(n) == 1) printf("Pooh\n");
            else printf("Piglet\n");
        } else {
            if (piglet_turn(n) == 1) printf("Piglet\n");
            else printf("Pooh\n");
        }
    }
    return 0;
}

int pooh_turn (int n) {
    if (n >= 1) {
        int flag_pooh = 0;
        if (pooh_record[n] != 2) return pooh_record[n];
        if (n <= a) return pooh_record[n] = 1;
        for (int i = 1 ; i <= a ; i++) {
            if (!piglet_turn(n - i)) {
                flag_pooh = 1;
            }
        }
        if (flag_pooh) return pooh_record[n] = 1;
        return pooh_record[n] = 0;
    }
}

int piglet_turn (int n) {
    if (n >= 1) {
        int flag_piglet = 0;
        if (piglet_record[n] != 2) return piglet_record[n];
        if (n <= b) return piglet_record[n] = 1;
        for (int i = 1 ; i <= b ; i++) {
            if (!pooh_turn(n - i)) {
                flag_piglet = 1;
            }
        }
        if (flag_piglet) return piglet_record[n] = 1;
        return piglet_record[n] = 0;
    }
}