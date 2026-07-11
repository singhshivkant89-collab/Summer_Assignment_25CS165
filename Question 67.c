#include <stdio.h>
#include <stdbool.h>

// Function to check if an element already exists in the result array
bool isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true; 
        }
    }
    return false;
}

// Function to find the intersection of two arrays
void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int intersection[100]; // Array to store intersection elements
    int k = 0;             // Index counter for the intersection array

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            // If a common element is found
            if (arr1[i] == arr2[j]) {
                // Check if it is already added to avoid duplicates
                if (!isDuplicate(intersection, k, arr1[i])) {
                    intersection[k] = arr1[i];
                    k++;
                }
                break; // Break internal loop since the match for this element is processed
            }
        }
    }

    // Print the final intersection array
    printf("Intersection of the two arrays: ");
    if (k == 0) {
        printf("None (No common elements)\n");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr1[] = {4, 9, 5, 4, 1};
    int arr2[] = {9, 4, 9, 8, 4, 2};
    
    // Calculate lengths of arrays dynamically
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    printf("\n\n");

    findIntersection(arr1, size1, arr2, size2);

    return 0;
}
