#include <stdio.h>
#include <string.h>

int n, record_letter[30], letter[30], frequency[3005], len, num, cnt, flag, flaggy;
char s[3005], p[3005], temp[3005], ans[3005][3005];

void bubble_frequency();
void bubble_letter();

int main() {
    scanf("%s", s);
    scanf("%d", &n);
    scanf("%s", p);
    len = strlen(s);
    for (int i = 0 ; i < n ; i++) record_letter[p[i] - 'a']++;
    for (int i = 0 ; i < len ; i++) {
        flag = 0, flaggy = 0;
        letter[s[i] - 'a']++, num++;
        if (i >= n) letter[s[i - n] - 'a']--, num--;
        if (num == n) {
            for (int j = 0 ; j < 30 ; j++) {
                if (letter[j] != record_letter[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                for (int j = 0 ; j < n ; j++) {
                    temp[j] = s[i + 1 - n + j];
                }
                for (int j = 0 ; j < cnt ; j++) {
                    if (strcmp(ans[j], temp) == 0) {
                        frequency[j]++;
                        flaggy = 1;
                        break;
                    }
                }
                if (!flaggy) {
                    frequency[cnt]++;
                    strcpy(ans[cnt], temp);
                    cnt++;
                }
            }
        }
    }
    printf("%d\n", cnt);
    bubble_frequency();
    bubble_letter();
    for (int i = 0 ; i < cnt ; i++) {
        printf("%s %d\n", ans[i], frequency[i]);
    }
    return 0;
}

void bubble_frequency() {
    int temp_f;
    char temp_s[3005];
    for (int i = 0 ; i < cnt - 1 ; i++) {
        for (int j = 0 ; j < cnt - 1 - i ; j++) {
            if (frequency[j] < frequency[j + 1]) {
                temp_f = frequency[j];
                frequency[j] = frequency[j + 1];
                frequency[j + 1] = temp_f;
                strcpy(temp_s, ans[j]);
                strcpy(ans[j], ans[j + 1]);
                strcpy(ans[j + 1], temp_s);
            }
        }
    }
}

void bubble_letter() {
    char temp_s[3005];
    for (int i = 0 ; i < cnt - 1 ; i++) {
        for (int j = 0 ; j < cnt - 1 - i ; j++) {
            if (frequency[j] == frequency[j + 1]) {
                for (int k = 0 ; k < n ; k++) {
                    if (ans[j][k] < ans[j + 1][k]) break;
                    if (ans[j][k] > ans[j + 1][k]) {
                        strcpy(temp_s, ans[j]);
                        strcpy(ans[j], ans[j + 1]);
                        strcpy(ans[j + 1], temp_s);
                        break;
                    }
                }
            }
        }
    }
}