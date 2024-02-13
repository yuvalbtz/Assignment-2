#include <stdio.h>

#define MAX_ITEMS 5
#define KNAPSACK_CAPACITY 20

// Function to find the maximum value of items that fit in the knapsack
int knapSack(int weights[], int values[], int selected_bool[]) {
    int W = KNAPSACK_CAPACITY; // Knapsack capacity
    int i, w;
    int K[MAX_ITEMS + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = (values[i - 1] + K[i - 1][w - weights[i - 1]] > K[i - 1][w]) ?
                               values[i - 1] + K[i - 1][w - weights[i - 1]] :
                               K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Determine which items are selected
    w = W;
    for (i = MAX_ITEMS; i > 0 && K[i][w] > 0; i--) {
        if (K[i][w] != K[i - 1][w]) {
            selected_bool[i - 1] = 1;
            w = w - weights[i - 1];
        }
    }

    // Return the maximum value
    return K[MAX_ITEMS][W];
}

// Function to print the selected items in reverse order
void printSelectedItems(int selected_bool[]) {
    printf("Selected Items (in reverse order): ");
    for (int i = MAX_ITEMS - 1; i >= 0; i--) {
        if (selected_bool[i]) {
            printf("%c ", 'A' + i);
        }
    }
    printf("\n");
}

int main() {
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    int selected_bool[MAX_ITEMS] = {0}; // Array to store selected items (0 or 1)

    // Input weights and values for each item
    printf("Enter weights and values for each item:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item %c (weight value): ", 'A' + i);
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Find the maximum value and selected items
    int maxTotalValue = knapSack(weights, values, selected_bool);

    // Display selected items in reverse order
    printSelectedItems(selected_bool);

    // Display the maximum total value
    printf("Maximum Total Value: %d\n", maxTotalValue);

    return 0;
}
