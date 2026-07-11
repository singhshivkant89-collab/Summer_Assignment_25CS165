#include <stdio.h>

int main() {
    // Initialize two sample arrays
    int arr1[] = {4, 2, 9, 6, 2, 8, 1};
    int arr2[] = {2, 7, 1, 9, 3, 2};
    
    // Calculate the size of both arrays dynamically
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // Array to temporarily store common elements and avoid duplicates
    int visited[100];
    int k = 0; // Tracks the count of unique common elements found
    
    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    
    printf("\n\nCommon elements are: ");
    
    // Step 1: Loop through each element of the first array
    for (int i = 0; i < size1; i++) {
        // Step 2: Loop through each element of the second array
        for (int j = 0; j < size2; j++) {
            // Check if a match is found
            if (arr1[i] == arr2[j]) {
                int already_counted = 0;
                
                // Step 3: Check if this element was already added to the results
                for (int x = 0; x < k; x++) {
                    if (arr1[i] == visited[x]) {
                        already_counted = 1;
                        break;
                    }
                }
                
                // Step 4: If it is a new common element, store and print it
                if (!already_counted) {
                    visited[k] = arr1[i];
                    k++;
                    printf("%d ", arr1[i]);
                }
                // Break out of the inner loop once a match for arr1[i] is processed
                break; 
            }
        }
    }
    
    // If no common elements were found
    if (k == 0) {
        printf("None");
    }
    
    printf("\n");
    return 0;
}
