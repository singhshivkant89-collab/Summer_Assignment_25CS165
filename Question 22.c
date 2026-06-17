#include <stdio.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, rem;

    // Take binary number input from the user
    printf("Enter a binary number (using 0s and 1s): ");
    scanf("%lld", &binary);

    long long temp = binary; // Keep a copy of the original input

    // Loop to convert binary to decimal
    while (temp > 0) {
        rem = temp % 10;          // Extract the last digit
        decimal += rem * base;    // Add the digit multiplied by current power of 2
        base *= 2;                // Increase the base power (1, 2, 4, 8, 16...)
        temp /= 10;               // Remove the last digit
    }

    // Print the final result
    printf("Binary: %lld\n", binary);
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}