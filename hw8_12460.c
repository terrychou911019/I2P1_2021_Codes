#include <stdio.h>
#include <string.h>

char str[30], ans[30];
int len, flag;

void bubble (char str[], int len);
void lex (int count, int t);

int main () {
    scanf("%s", str);
    len = strlen(str);
    bubble(str, len);
    lex(0, 0);
    printf("\n");
    return 0;
}

void bubble (char str[], int len) {
    int temp;
    for (int i = 0 ; i < len - 1 ; i++) {
        for (int j = 0 ; j < len - 1 - i ; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void lex (int count, int t) { //count == 數到第count個   t == a[]要和s[t]一樣
    if (t < len) {
        ans[count] = str[t];
        if (count + 1 >= 4) {
            if (flag) printf(", ");
            for (int i = 0 ; i < count + 1 ; i++) {
                printf("%c", ans[i]);  
            }
            flag = 1;
        }
        lex (count + 1, t + 1);
        lex (count, t + 1);
    }
}
