#include <stdio.h>
int main (){
    int t, m ,n, a, b, c, d, ka, kb;
    char ch;
    scanf("%d", &t);
    for (int i = 0 ; i < t ; i++){
        scanf("%d %d", &n, &m);
        char wood[n + 1][m + 1];
        for (int j1 = 0 ; j1 < n ; j1++){
            for (int j2 = 0 ; j2 < m ; j2++){
                scanf(" %c", &ch);
                wood[j1][j2] = ch;
            }
        }
        for (int j3 = 0 ; j3 < n ; j3++){
            wood[j3][m] = 0;
        }
        for (int j4 = 0 ; j4 < m ; j4++){
            wood[n][j4] = 0;
        }
        a = 0, b = 0, c = 0, d = 0;
        int ta = 0, tb = 0, tc = 0, td = 0;
        for (int i1 = 0 ; i1 < n ; i1++){
            for (int i2 = 0 ; i2 < m ; i2++){
                if (wood[i1][i2] == 'o'){
                    a++;
                    if (wood[i1][i2] != wood[i1][i2 + 1]){
                        if (a > ta) ta = a;
                        a = 0;
                    }
                }
                if (wood[i1][i2] == '#') {
                    b++;
                    if (wood[i1][i2] != wood[i1][i2 + 1]){
                        if (b > tb) tb = b;
                        b = 0;
                    }
                }
            }
        }
        for (int i3 = 0 ; i3 < m ; i3++){
            for (int i4 = 0 ; i4 < n ; i4++){   
                if (wood[i4][i3] == 'o'){
                    c++;
                    if (wood[i4][i3] != wood[i4 + 1][i3]){
                        if (c > tc) tc = c;
                        c = 0; 
                    }
                }
                if (wood[i4][i3] == '#'){
                    d++;
                    if (wood[i4][i3] != wood[i4 + 1][i3]){
                        if (d > td) td = d;
                        d = 0;
                    }
                }
            }
        }
        ka = ta;
        if (tc > ta) ka = tc;
        kb = tb;
        if (td > tb) kb = td;
        printf("%d %d\n", ka, kb);
    }
    return 0;
}