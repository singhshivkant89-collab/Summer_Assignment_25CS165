#include <stdio.h>
#include <stdbool.h>

// Function to find and print the pair with the given sum
bool findPairWithSum(int arr[], int size, int targetSum) {
    // Outer loop selects the first element
    for (int i = 0; i < size; i++) {
        // Inner loop searches for the second element
        for (int j = i + 1; j < size; j++) {
            // Check if the sum of the pair matches the target
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: %d and %d (at indices %d and %d)\n", arr[i], arr[j], i, j);
                return true; 
            }
        }
    }
    
    // Return false if no such pair exists
    return false;
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget Sum: %d\n\n", targetSum);

    if (!findPairWithSum(arr, size, targetSum)) {
        printf("No pair found with the given sum.\n");
    }

    return 0;
}
