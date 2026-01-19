#include <stdio.h>

// Recursive Binary Search function
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If element is present at middle
        if (arr[mid] == target)
            return mid;

        // If element is smaller than mid, search in left subarray
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Else search in right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // Element not present in array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Element to search: %d\n", target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("Element not found in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}