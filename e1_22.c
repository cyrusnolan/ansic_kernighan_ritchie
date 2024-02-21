#include <stdio.h>
#define COLUMNS 15
#define LIMIT 500

void getLine(char line[], char foldedLines[]) {
    int c, i, j, k, col, blankIndex, foldedLinesIndex, trailingBlanks, offset;
    i = col = blankIndex = foldedLinesIndex = trailingBlanks = 0;
    offset = 1;
    while ((c = getchar()) != EOF && i < LIMIT - 1) {
        line[i++] = c; 
    }
    line[i] = '\0';
    for (j = 0; j <= i; ++j) {
        ++col;
        if ((line[j-1] != ' ' && line[j-1] != '\t') && (line[j] == ' ' || line[j] == '\t'))
            blankIndex = col - 1;
        else if ((line[j-1] == ' ' && line[j-1] == '\t') && (line[j] == ' ' || line[j] == '\t'))
            ++trailingBlanks;
        if (line[j] == '\n' || line[j] == '\0') {
            for (int k = 0; k < col; ++k) {
                foldedLines[foldedLinesIndex] = line[j + 1 - col + k];
                ++foldedLinesIndex;
            }
            col = 0;
            blankIndex = 0;
        }
        else if (col == COLUMNS) {
            if (blankIndex == 0) {
                blankIndex = col;
                offset = 0;
            }
            for (k = 0; k < blankIndex; ++k) {
                foldedLines[foldedLinesIndex] = line[j + 1 - col + k];
                ++foldedLinesIndex;
            }
            foldedLines[foldedLinesIndex] = '\n';
            ++foldedLinesIndex;
            j = j - col + blankIndex + trailingBlanks + offset;
            printf("\n%d\n", j);
            while (line[j+1] == ' ')
                ++j;
            col = 0;
            blankIndex = 0;
            offset = 1;
        }
    }
    if (foldedLines[foldedLinesIndex - 1] == '\n')
        foldedLines[foldedLinesIndex - 1] = '\0';
    else
        foldedLines[foldedLinesIndex] = '\0';
}


int main() {
    char line[LIMIT];
    char foldedLines[LIMIT];
    getLine(line, foldedLines);
    printf("\n%s\n", foldedLines);
    return 0;
}