#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "function.h"

#define maxn 1000
#define maxl 1000

int P;
char M[1000010];

void solver(char **ptr, int *n, int P, char *M);

int main() {
    int n = 0;
    char Table[maxn][maxl+1]; // +1 for null char
    char *ptr[maxn];

    for (int i = 0; i < maxn; i++) {
        for(int j=0; j < maxl + 1; j++)
            Table[i][j] = '\0';
        ptr[i] = &Table[i][0];
    }

    scanf("%d", &P);
    scanf("%s", M);

    solver(ptr, &n, P, M);
    
    int cnt = 0;
    printf("%d\n", n); // the # of words
    for(int i=0; i<P; i++){
        if( strlen( Table[i] ) != 0 ){
            // if the position is non-empty.
            if( cnt < n-1 )
                printf("%s ", Table[i]);
            else
                printf("%s\n", Table[i]);
            cnt++;
        }
    }
    return 0;
}

void solver(char **ptr, int *n, int P, char *M) {
    int len = strlen(M), num = 0, k[1005], recorded_num, flag;
    for (int i = 0 ; i < 1005 ; i++) k[i] = 0;
    for (int i = 0 ; i < len ; i++) {
        if ('0' <= M[i] && M[i] <= '9') {
            num = num * 10 + M[i] - '0';
            flag = 1;
        } else {
            if (flag) {
                recorded_num = num;
                num = 0;
                flag = 0;
            }
            *(ptr[recorded_num % P] + k[recorded_num % P]) = M[i];
            k[recorded_num % P]++;
        }
    }
    for (int i = 0 ; i < 1000 ; i++) {
        if (*(ptr[i]) != '\0') *n = *n + 1;
    }
}