#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_PATTERN_LENGTH 100

int horspoolMatch(char text[], char pattern[]) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    if (patternLen > textLen)
        return -1; // Pattern is longer than the text, no match possible.

    int shiftTable[256];
    for (int i = 0; i < 256; i++) {
        shiftTable[i] = patternLen;
    }

    for (int i = 0; i < patternLen - 1; i++) {
        shiftTable[pattern[i]] = patternLen - 1 - i;
    }

    int i = patternLen - 1;
    while (i < textLen) {
        int k = 0;
        while (k < patternLen && pattern[patternLen - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == patternLen) {
            return i - patternLen + 1; // Match found, return the starting index.
        }

        i += shiftTable[text[i]];
    }

    return -1; // Pattern not found in the text.
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char pattern[MAX_PATTERN_LENGTH];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove the newline character from fgets.

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character from fgets.

    int matchIndex = horspoolMatch(text, pattern);

    if (matchIndex != -1) {
        printf("Pattern found at index: %d\n", matchIndex);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
