#include <stdio.h>
void hanoi (int n, char a, char b, char c);
int main (){
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    return 0;
}
void hanoi (int n, char a, char b, char c) {
    if (n == 1) {
        printf("%d\n", n);
    }
    else {
        hanoi(n - 1, a, c, b);
        printf("%d\n", n);
        hanoi(n - 1, b, a, c);
    }
}