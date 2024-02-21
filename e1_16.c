#include <stdio.h>
#define MAXLINE 10

int pullline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    int c;
    while ((len = pullline(line,MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                ++len;
            }
        }
        if (c == '\n')
            ++len;
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("\nLength: %d\nLine: %s\n", max, longest);
    else
        printf("No line");
    return 0;
}

int pullline(char s[], int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
