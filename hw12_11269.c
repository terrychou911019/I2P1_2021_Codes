#include <stdio.h>
#include <string.h>
#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];
int len, cursor = 0, rb = -1;

int main() {
    fgets(input, MAX_SIZE, stdin);
    len = strlen(input);
    for (int i = 0 ; i < len ; i++) {
        if (input[i] == '/') {
            if (input[i + 1] == 'b') {
                if (cursor == 0) {}
                else if (cursor == rb + 1) {
                    cursor--;
                    rb--;
                } else {
                    for (int j = cursor ; j <= rb ; j++) {
                        content[j - 1] = content[j];
                    }
                    cursor--;
                    rb--;
                }
                i += 9;
            }
            else if (input[i + 1] == 'n') {
                if (cursor != rb + 1) {
                    for (int j = rb ; j >= cursor ; j--) {
                        content[j + 1] = content[j];
                    }
                }
                content[cursor] = '\n';
                cursor++;
                rb++;
                i += 7;
            }
            else if (input[i + 1] == 'l') {
                if (cursor != 0) cursor--;
                i += 4;
            }
            else if (input[i + 1] == 'r') {
                if (cursor != rb + 1) cursor++;
                i += 5;
            }
        } else {
            if (cursor != rb + 1) {
                for (int j = rb ; j >= cursor ; j--) {
                    content[j + 1] = content[j];
                }
            }
            content[cursor] = input[i];
            cursor++;
            rb++;
        }
    }   
    printf("%s", content);
    return 0;
}