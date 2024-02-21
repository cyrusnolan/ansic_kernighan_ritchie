// Check for unblanced braces

#include <stdio.h>

#define LIM 500

void readCode(char prog[]) {
    int i = 0;
    while ((char c = getchar()) != EOF && i < LIM - 1)
        prog[i++] = c;
    if (i == LIM)
        printf("Caution: Character limit reached\n");
    if (prog[i-1] == '\n')
        prog[i-1] == '\0';
    else
        prog[i] = '\0';
}

void checkProgram(char prog[]) {
    int i = 0;
    int brace = 0;
    int line = 0;
    while (prog[i] != '\0') {
        if (prog[i] == '{') {
            ++brace;
        } else if (prog[i] == '}') {
            if (brace < 1)
                printf("Unclosed brace");
            else
                --brace;
        }
    }
    for (j = 0; j < i; ++j) {
        // Track line number
        if (fromP[j] == '\n')
            ++line;
        
        // Handle braces
        if (fromP[j] == '{' && brace == 0) {
            ++brace;
            braceIndex = line;
        }
        else if (fromP[j] == '{')
            ++brace;
        else if (fromP[j] == '}' && brace == 0) {
            --brace;
            braceIndex = line;
        }
        else if (fromP[j] == '}')
            --brace;
    }
    if (brace < 0)
        printf("Extra brace on line %i\n", braceIndex);
    else if (brace > 0)
        printf("Open brace on line %i\n", braceIndex);
}

int main() {
    char prog[LIM];
    checkProgram(fromP);
    return 0;
}
