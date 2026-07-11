#include <stdio.h>

// Function to perform an optimized bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    // Outer loop for total number of passes
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Reset flag for each pass
        
        // Inner loop for comparing adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped in the inner loop, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
