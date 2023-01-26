#include <stdio.h>
int way (int x);
int main (){
    int n, x;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &x);
        printf("%d\n", way (x));
    }
    return 0;
}
int way (int x){
    int answer;
    if (x == 1) answer = 1;
    if (x == 2) answer = 2;
    if (x >= 3){
        answer = way (x - 1) + way (x - 2);
    }
    return answer;
}