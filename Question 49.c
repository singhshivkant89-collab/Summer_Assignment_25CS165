#include <stdio.h>

int main() {
    int n, i;

    // Ask the user for the number of elements
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Declare an array of size n
    int arr[n];

    // Input array elements from the user
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the stored array elements
    printf("\nThe elements in the array are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
