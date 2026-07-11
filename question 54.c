#include <stdio.h>

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n]; // Array to keep track of counted elements

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize all elements as not visited
    }

    printf("\n--- Element Frequencies ---\n");

    // Logic to calculate frequency
    for (int i = 0; i < n; i++) {
        // Skip this element if it has already been counted
        if (visited[i] == 1) {
            continue;
        }

        int count = 1; // Start counting the current element

        // Check the rest of the array for duplicates
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark the duplicate element as visited
            }
        }

        // Print the final frequency of the unique element
        printf("Element %d appears %d time(s)\n", arr[i], count);
    }

    return 0;
}
