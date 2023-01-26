#include <stdio.h>
#include <string.h>

char str[12], record[12];
int visit[12], len, temp;

void bubble (char str[]);
void change (char str[], int n);

int main () {
    scanf("%s", str);
    len = strlen(str);
    bubble(str);
    change(str, 0);
    return 0;
}

void change (char str[], int n) {
    if (n == len) {
        printf("%s\n", record);
        return;
    }
    char head = '\0';
    for (int i = 0 ; i < len ; i++) {
        if (!visit[i]) {
            if (str[i] != head) head = str[i];
            else continue;
            record[n] = str[i];
            visit[i] = 1;
            change(str, n + 1);
            visit[i] = 0;
        }
    }
}

void bubble (char str[]) {
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