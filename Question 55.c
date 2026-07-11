#include <stdio.h>
#include <limits.h> // Required for INT_MIN

int findSecondLargest(int arr[], int size) {
    // There must be at least two elements
    if (size < 2) {
        return INT_MIN; 
    }

    // Initialize both tracking variables to the lowest possible integer value
    int first_largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < size; i++) {
        // If current element is greater than the highest found so far
        if (arr[i] > first_largest) {
            second_largest = first_largest; // Old largest becomes second largest
            first_largest = arr[i];          // Update largest
        }
        // If current element is smaller than first but greater than second
        else if (arr[i] > second_largest && arr[i] != first_largest) {
            second_largest = arr[i];
        }
    }

    return second_largest;
}

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int result = findSecondLargest(arr, size);

    // If second_largest remains INT_MIN, it means a valid distinct second largest wasn't found
    if (result == INT_MIN) {
        printf("The second largest element does not exist (all elements might be equal or insufficient data).\n");
    } else {
        printf("The second largest element is: %d\n", result);
    }

    return 0;
}
