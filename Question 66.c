#include <stdio.h>

// Helper function to check if an element already exists in an array
int isPresent(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Element found (duplicate)
        }
    }
    return 0; // Element not found
}

// Function to find the union of two arrays
int findUnion(int arr1[], int size1, int arr2[], int size2, int unionArr[]) {
    int k = 0; // Tracks the size of the union array

    // 1. Copy all unique elements from the first array
    for (int i = 0; i < size1; i++) {
        if (!isPresent(unionArr, k, arr1[i])) {
            unionArr[k] = arr1[i];
            k++;
        }
    }

    // 2. Copy unique elements from the second array
    for (int i = 0; i < size2; i++) {
        if (!isPresent(unionArr, k, arr2[i])) {
            unionArr[k] = arr2[i];
            k++;
        }
    }

    return k; // Return final size of the union array
}

int main() {
    int arr1[] = {1, 3, 7, 3, 9};
    int arr2[] = {1, 4, 6, 7, 7};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // The maximum possible size of the union is the sum of both array sizes
    int unionArr[size1 + size2]; 
    
    int unionSize = findUnion(arr1, size1, arr2, size2, unionArr);

    // Print the result
    printf("Union of the two arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
