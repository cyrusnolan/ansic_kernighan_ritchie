#include <stdio.h>
#define LIM 500

void getProgram(char fromP[], char toP[]) {
    int c, i, j, k, cond;
    i = j = k = 0;
    while ((c = getchar()) != EOF && i < LIM - 1) {
        fromP[i++] = c;
    }
    if (fromP[i-1] == '\n')
        fromP[i-1] = '\0';
    else
        fromP[i] = '\0';
    for (k; k<i; ++k) {
        if (fromP[k] == '/' && fromP[k+1] == '/')
            cond = 1;
        else if (fromP[k] == '/' && fromP[k+1] == '*')
            cond = 1;
        else if (fromP[k] == '*' && fromP[k+1] == '/')
            cond = 1;
        else {
            toP[j++] = fromP[k];
            cond = 0;
        }
        if (cond == 1) {
            ++k;
            while (fromP[k+1] == ' ')
                ++k;
        }
    }
}

int main() {
    char fromP[LIM];
    char toP[LIM];
    getProgram(fromP, toP);
    printf("%s\n", toP);
}