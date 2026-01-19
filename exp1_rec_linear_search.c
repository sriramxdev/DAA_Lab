#include <stdio.h>

// Recursive function to perform linear search
int recursiveLinearSearch(int arr[], int size, int key, int index) {
    // Base case: if index reaches size, element not found
    if (index == size) {
        return -1;
    }

    // If element found at current index
    if (arr[index] == key) {
        return index;
    }

    // Recursive call for next index
    return recursiveLinearSearch(arr, size, key, index + 1);
}

int main() {
    int n, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call recursive linear search starting from index 0
    result = recursiveLinearSearch(arr, n, key, 0);

    if (result != -1) {
        printf("Element %d found at index %d (position %d)\n", key, result, result + 1);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}