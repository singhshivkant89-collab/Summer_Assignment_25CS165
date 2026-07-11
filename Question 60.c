#include <stdio.h>

// Function to move all zeroes to the end of the array
void moveZeroesToEnd(int arr[], int size) {
    int count = 0; // Tracks the position for the next non-zero element

    // Step 1: Traverse the array. If the element is non-zero,
    // move it to the front at the 'count' index.
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    // Step 2: Fill the remaining positions of the array with zeroes
    while (count < size) {
        arr[count] = 0;
        count++;
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 0, 3, 0, 12, 0, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    moveZeroesToEnd(arr, size);

    printf("Modified Array: ");
    printArray(arr, size);

    return 0;
}
