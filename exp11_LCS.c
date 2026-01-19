#include <stdio.h>
#include <stdlib.h>

// Structure to represent a pair
typedef struct {
    int a;
    int b;
} Pair;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return p1->a - p2->a;
}

// Function to find the longest chain subsequence
int longestChainSubsequence(Pair pairs[], int n) {
    // Sort pairs by first element
    qsort(pairs, n, sizeof(Pair), compare);

    // dp[i] stores the length of longest chain ending at index i
    int *dp = (int *)malloc(n * sizeof(int));

    // Initialize all dp values to 1
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // Compute longest chain for each pair
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If pairs[j].b < pairs[i].a, we can chain them
            if (pairs[j].b < pairs[i].a && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum length
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }

    free(dp);
    return maxLength;
}

int main() {
    int n;

    printf("Enter the number of pairs: ");
    scanf("%d", &n);

    Pair *pairs = (Pair *)malloc(n * sizeof(Pair));

    printf("Enter the pairs (a b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pairs[i].a, &pairs[i].b);
    }

    int result = longestChainSubsequence(pairs, n);

    printf("Length of longest chain subsequence: %d\n", result);

    free(pairs);
    return 0;
}