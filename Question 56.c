#include <stdio.h>

void findDuplicates(int arr[], int size) {
    int foundDuplicate = 0;

    printf("Duplicate elements in the array: ");
    
    // Outer loop picks each element one by one
    for (int i = 0; i < size; i++) {
        // Check if the element was already processed as a duplicate to avoid double printing
        int alreadyPrinted = 0;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                alreadyPrinted = 1;
                break;
            }
        }
        
        // If it was already printed, skip to the next element
        if (alreadyPrinted) {
            continue;
        }

        // Inner loop compares the picked element with the rest of the array
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                foundDuplicate = 1;
                break; // Break to avoid printing the same element multiple times if it appears more than twice
            }
        }
    }

    if (!foundDuplicate) {
        printf("None");
    }
    printf("\n");
}

int main() {
    // Example array with duplicates (2 and 4 appear multiple times)
    int arr[] = {4, 2, 7, 2, 8, 4, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Displaying the original array
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call function to find and print duplicates
    findDuplicates(arr, size);

    return 0;
}
