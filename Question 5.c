#include <stdio.h>
#include <stdlib.h> // Included for abs() function

int main() {
    int num, originalNum, rem, sum = 0;

    // Prompt user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    originalNum = num;

    // Convert to absolute value to correctly handle negative numbers
    num = abs(num);

    // Loop to isolate and sum up each individual digit
    while (num > 0) {
        rem = num % 10;  // 1. Get the last digit
        sum += rem;      // 2. Add the digit to sum
        num /= 10;       // 3. Remove the last digit from number
    }
