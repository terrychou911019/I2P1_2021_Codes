#include <stdio.h>
#include <string.h>
int main () {
    int n, m, length;
    int k = 0;
    int flag = 0;
    int len[101];
    
    scanf("%d %d", &n, &m); 
    char s0[1001], s1[n][1001], s2[1001];

    for (int i1 = 0 ; i1 <= n - 1 ; i1++){
        scanf("%s", s0);
        len[i1] = strlen(s0);
        for (int i2 = 0 ; i2 <= len[i1] - 1 ; i2++){
            s1[i1][i2] = s0[i2];
        }
    }
    for (int j1 = 1 ; j1 <= m ; j1++){
        flag = 0;
        scanf("%s", s2);
        for (int j2 = 0 ; j2 <= n - 1 ; j2++){
            k = 0;
            for (int j3 = 0 ; j3 <= len[j2] - 1 ; j3++){
                if (s2[j3] == s1[j2][j3]){
                    k = k + 1;
                }
                if (k == len[j2]){
                    printf("Yes\n");
                    k = 0;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1){
            continue;
        }
        if (!flag){
            printf("No\n");
        }
    }
    return 0;
}