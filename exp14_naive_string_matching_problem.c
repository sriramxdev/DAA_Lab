#include <stdio.h>
#include <string.h>

void naiveStringMatch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("\nSearching for pattern in text...\n\n");

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Naive String Matching Algorithm\n");
    printf("================================\n\n");

    printf("Enter the text: ");
    scanf("%[^\n]", text);

    getchar();

    printf("Enter the pattern to search: ");
    scanf("%[^\n]", pattern);

    printf("\n");
    naiveStringMatch(text, pattern);

    return 0;
}