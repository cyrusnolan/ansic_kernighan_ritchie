#include <stdio.h>

#define SPACE 8
#define MAXCHARS 500

void convertSpacesToTabsAndBlanks(char input[], int size) {
    int i = 0; // index of string input
    int pos = 0; // position of character in line
    int numSpaces = 0;
    int c, tabGain, tabs, blanks;
    while ((c = getchar()) != EOF && i < size - 1) {
        if (c == ' ')
            ++numSpaces;
        else if (numSpaces == 0) {
            input[i++] = c;
            ++pos;
        }
        else {
            tabGain = SPACE - pos % SPACE;
            if (numSpaces >= tabGain) {
                tabs = 1;
                numSpaces -= tabGain;
            }
            tabs += numSpaces / SPACE;
            blanks = numSpaces % SPACE;
            for (int j = 0; j < tabs; ++j) {
                input[i++] = '\t';
                ++pos;
            }
            for (int j = 0; j < blanks; ++j) {
                input[i++] = ' ';
                ++pos;
            }
            numSpaces = 0;
            input[i++] = c;
            ++pos;
        }
        if (c == '\n')
            pos = 0;
    }
    if (input[i-1] == '\n')
        input[i-1] = '\0';
    else
        input[i] = '\0';
}

int main() {
    char input[MAXCHARS];
    convertSpacesToTabsAndBlanks(input, MAXCHARS);
    printf("%s\n", input);
    return 0;
}