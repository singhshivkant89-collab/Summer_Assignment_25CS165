#include <stdio.h>

int main() {
    int size, i;
    int even_count = 0;
    int odd_count = 0;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size]; // Declare array of the given size

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Process each element to count even and odd numbers
    for(i = 0; i < size; i++) {
        // A number is even if it leaves a remainder of 0 when divided by 2
        if(arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Print the results
    printf("\nTotal Even elements: %d", even_count);
    printf("\nTotal Odd elements: %d\n", odd_count);

    return 0;
}
