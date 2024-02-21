#include <stdio.h>

#define TAB_WIDTH 8
#define MAXCHARS 500

int main() {
    char input[MAXCHARS];
    int i = 0; // index of string input
    int pos = 0; // position of character in line
    int numBlanks, c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            input[i] = c;
            ++i;
            pos = 0;
        }
        else if (c == '\t') {
            numBlanks = TAB_WIDTH - pos % TAB_WIDTH;
            if (numBlanks == 0)
                numBlanks = TAB_WIDTH;
            for (int j = 0; j < numBlanks; ++j) {
                input[i] = ' ';
                ++i;
                ++pos;
            }
        } else {
            input[i] = c;
            ++i;
            ++pos;
        }
    }
    if (input[i - 1] == '\n')
        input[i - 1] = '\0';
    printf("%s\n", input);
}

