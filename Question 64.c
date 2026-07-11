#include <stdio.h>

int main() {
    int arr[100];
    int size;

    // Ask user for the number of elements
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &size) != 1) return 1;

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Logic to remove duplicate elements
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // If a duplicate is found
            if (arr[i] == arr[j]) {
                // Shift all subsequent elements one position left
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                // Reduce the logical size of the array
                size--;
                // Decrement j to check the newly shifted element at the same index
                j--; 
            }
        }
    }

    // Print the modified array
    printf("\nArray after removing duplicates:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
