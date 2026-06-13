#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, temp, rem;
    long long product = 1; // Used long long to prevent overflow with large products

    // Prompt user for input
    printf("Enter an integer number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Keep a copy of the original number for display
    temp = num;

    // Handle negative numbers by converting to absolute value
    num = abs(num);

    // Special case for zero
    if (num == 0) {
        product = 0;
    } else {
        // Loop to extract digits and multiply them
        while (num > 0) {
            rem = num % 10;       // Get the last digit
            product = product * rem; // Multiply to the total product
            num = num / 10;       // Remove the last digit
        }
    }

    // Print the final result
    printf("The product of the digits of %d is: %lld\n", temp, product);

    return 0;
}