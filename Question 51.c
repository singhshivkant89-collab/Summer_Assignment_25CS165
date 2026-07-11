#include <stdio.h>

int main() {
    int arr[100];
    int n, i;
    int largest, smallest;

    // Ask the user for the number of elements
    printf("Enter the number of elements (1 to 100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input size.\n");
        return 1;
    }

    // Read elements from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Assume the first element is both the largest and smallest
    largest = arr[0];
    smallest = arr[0];

    // Traverse the array to update largest and smallest values
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    // Print the final results
    printf("\nLargest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}
