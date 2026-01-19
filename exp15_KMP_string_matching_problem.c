#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
void computeLPSArray(char* pattern, int M, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search algorithm
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Create LPS array
    int* lps = (int*)malloc(sizeof(int) * M);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    printf("Searching for pattern \"%s\" in text \"%s\"\n\n", pattern, text);

    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }

    free(lps);
}

int main() {
    char text[1000], pattern[1000];

    printf("KMP String Matching Algorithm\n");
    printf("==============================\n\n");

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0; // Remove newline

    printf("\n");

    KMPSearch(pattern, text);

    return 0;
}