#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char line[MAXLINE];
    int c, i = 0;
    while ((c = getchar()) != EOF && i < MAXLINE - 1) {
        if (c == '\n') {
            line[i] = '\0';
            reverse(line);
            printf("%s\n", line);
            i = 0;
        } else {
            line[i++] = c;
        }
    }
    return 0;
}
