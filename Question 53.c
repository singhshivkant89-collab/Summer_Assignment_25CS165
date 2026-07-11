#include <stdio.h>

// Function to perform linear search
// Returns the index of the element if found, otherwise returns -1
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

int main() {
    int n, target, result;

    // Get the number of elements from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target value to search for
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    // Call the linear search function
    result = linearSearch(arr, n, target);

    // Print the result
    if (result != -1) {
        printf("Element %d found at index %d (position %d).\n", target, result, result + 1);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
