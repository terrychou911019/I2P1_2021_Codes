#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cat {
    char name[50];
    int occup;
    int age;
} cat;

int cmp(const void *a, const void *b) {
    cat ca = *(cat *)a;
    cat cb = *(cat *)b;
    if (ca.occup == cb.occup) {
        if (ca.occup == 5) {
            if (ca.age > cb.age) return 1;
            else if (ca.age < cb.age) return -1;
            else if (ca.age == cb.age) return strcmp(ca.name, cb.name);
        } else {
            if (ca.age > cb.age) return -1;
            else if (ca.age < cb.age) return 1;
            else if (ca.age == cb.age) return strcmp(ca.name, cb.name);
        }
    }
    else if (ca.occup > cb.occup) return 1;
    else if (ca.occup < cb.occup) return -1;
}

int main() {
    int n, m;
    char temp[50];
    cat cats[10010];
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0 ; i < n ; i++) {
            scanf("%s %s %d", cats[i].name, temp, &(cats[i].age));
            switch (temp[0]) {
                case 'e':
                    cats[i].occup = 1;
                    break;
                case 'n':
                    cats[i].occup = 2;
                    break;
                case 'k':
                    cats[i].occup = 3;
                    break;
                case 'w':
                    cats[i].occup = 4;
                    break;
                case 'a':
                    cats[i].occup = 5;
                    break;
                case 'm':
                    cats[i].occup = 6;
                    break;
                case 'd':
                    cats[i].occup = 7;
                    break;
                case 'l':
                    cats[i].occup = 8;
                    break;
            }
        }
        qsort(cats, n, sizeof(cat), cmp);
        for (int i = 0 ; i < n && i < m ; i++) {
            printf("%s\n", cats[i].name);
        }
    }
    return 0;
}