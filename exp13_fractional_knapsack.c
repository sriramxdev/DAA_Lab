#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;
    int weight;
    double ratio; // value/weight ratio
} Item;

// Comparison function for qsort (descending order of ratio)
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item2->ratio > item1->ratio)
        return 1;
    else if (item2->ratio < item1->ratio)
        return -1;
    return 0;
}

// Function to implement fractional knapsack
double fractionalKnapsack(int capacity, Item items[], int n) {
    int i;

    // Calculate ratio for each item
    for (i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items by ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Add items to knapsack
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Add whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: weight = %d, value = %d (100%% taken)\n", 
                   i + 1, items[i].weight, items[i].value);
        } else {
            // Add fraction of item
            int remainingCapacity = capacity - currentWeight;
            if (remainingCapacity > 0) {
                double fraction = (double)remainingCapacity / items[i].weight;
                totalValue += items[i].value * fraction;
                printf("Item %d: weight = %d, value = %d (%.2f%% taken)\n", 
                       i + 1, items[i].weight, items[i].value, fraction * 100);
                break;
            }
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    printf("\nItems selected:\n");
    double maxValue = fractionalKnapsack(capacity, items, n);

    printf("\nMaximum value in knapsack: %.2f\n", maxValue);

    return 0;
}