#include <stdio.h>

char wood[1005][1005];

int main()
{
    int t, n ,m, a_r, a_c, a_d, b_r, b_c, b_d, ta_r, ta_c, ta_d, tb_r, tb_c, tb_d, ka, kb;
    char ch;
    scanf("%d", &t);
    for (int i = 0 ; i < t ; i++) {
        scanf("%d %d", &n, &m);
        for (int i1 = 1 ; i1 < n + 1 ; i1++) {
            for (int i2 = 1 ; i2 < m + 1 ; i2++) {
                scanf(" %c", &ch);
                wood[i1][i2] = ch;
            }
        }
        /*for (int i5 = 0 ; i5 < m + 2 ; i5++) wood[0][i5] = '0';
        for (int i6 = 0 ; i6 < m + 2 ; i6++) wood[n + 1][i6] = '0';
        for (int i7 = 0 ; i7 < n + 2 ; i7++) wood[i7][0] = '0';
        for (int i8 = 0 ; i8 < n + 2 ; i8++) wood[i8][m + 1] = '0';*/
        for (int i3 = 0 ; i3 < n + 2 ; i3++) {
            for (int i4 = 0 ; i4 < m + 2 ; i4++) {
                if (i4 < m + 1) printf("%c ", wood[i3][i4]);
                else printf("%c\n", wood[i3][i4]);
            }
        }
        a_r = 0, a_c = 0, a_d = 0, b_r = 0, b_c = 0, b_d = 0, ta_r = 0, ta_c = 0, ta_d = 0, tb_r = 0, tb_c = 0, tb_d = 0;
        for (int j1 = 1 ; j1 < n + 1 ; j1++) {
            for (int j2 = 1 ; j2 < m + 1 ; j2++) {
                if (wood[j1][j2] == 'o') {
                    a_r++;
                    if (wood[j1][j2] != wood[j1][j2 + 1]) {
                        if (a_r > ta_r) ta_r = a_r;
                        a_r = 0;
                    }
                }
                if (wood[j1][j2] == '#') {
                    b_r++;
                    if (wood[j1][j2] != wood[j1][j2 + 1]) {
                        if (b_r > tb_r) tb_r = b_r;
                        b_r = 0;
                    }
                }
            }
        }
        for (int j3 = 1 ; j3 < m + 1 ; j3++) {
            for (int j4 = 1 ; j4 < n + 1 ; j4++) {
                if (wood[j4][j3] == 'o') {
                    a_c++;
                    if (wood[j4][j3] != wood[j4 + 1][j3]) {
                        if (a_c > ta_c) ta_c = a_c;
                        a_c = 0;
                    }
                }
                if (wood[j4][j3] == '#') {
                    b_c++;
                    if (wood[j4][j3] != wood[j4 + 1][j3]) {
                        if (b_c > tb_c) tb_c = b_c;
                        b_c = 0;
                    }
                }
            }
        }
        for (int j5 = 1 ; j5 < n + 1 ; j5++) {
            for (int j6 = 1 ; j6 < m + 1 ; j6++) {
                if (wood[j5][j6] == 'o') {
                    a_d++;
                    if (wood[j5][j6] != wood[j5 + 1][j6 + 1]) {
                        if (a_d > ta_d) ta_d = a_d;
                        a_d = 0;
                    }
                }
                if (wood[j5][j6] == '#') {
                    b_d++;
                    if (wood[j5][j6] != wood[j5 + 1][j6 + 1]) {
                        if (b_d > tb_d) tb_d = b_d;
                        b_d = 0;
                    }
                }
            }
        }
        for (int j7 = 1 ; j7 < n + 1 ; j7++) {
            for (int j8 = m ; j8 > 0 ; j8--) {
                if (wood[j7][j8] == 'o') {
                    a_d++;
                    if (wood[j7][j8] != wood[j7 + 1][j8 - 1]) {
                        if (a_d > ta_d) ta_d = a_d;
                        a_d = 0;
                    }
                }
                if (wood[j7][j8] == '#') {
                    b_d++;
                    if (wood[j7][j8] != wood[j7 + 1][j8 - 1]) {
                        if (b_d > tb_d) tb_d = b_d;
                        b_d = 0;
                    }
                }
            }
        }
        ka = ta_r;
        if (ta_c > ka) ka = ta_c;
        if (ta_d > ka) ka = ta_d;
        kb = tb_r;
        if (tb_c > kb) kb = tb_c;
        if (tb_d > kb) kb = tb_d;
        printf("%d %d\n", ka, kb);
    }
    return 0;
}
