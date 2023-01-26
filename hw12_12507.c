#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cnt, len_str, len_target;;
char str[1000000], target[25], limit[20] = {' ', '\n', '-', '/', ':', '(', ')', '[', ']', ',', '.'};
char *token;

int main() {
    scanf("%s", target);
    len_target = strlen(target);
    for (int i = 0 ; i < len_target ; i++) target[i] = tolower(target[i]);
    while (fgets(str, 1000000, stdin) != NULL) {
        len_str = strlen(str);
        for (int i = 0 ; i < len_str ; i++) str[i] = tolower(str[i]);
        token = strtok(str, limit);
        while (token != NULL) {
            if (!strcmp(token, target)) cnt++;
            token = strtok(NULL, limit);
        }
    }
    printf("%d\n", cnt);
    return 0;
}