#include <stdio.h>

// Function declaration
int isPerfect(int num);

int main() {
    int number;

    // User input
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Call the function and print the result
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}

/**
 * Function to check if a number is a perfect number.
 * Returns 1 if perfect, 0 otherwise.
 */
int isPerfect(int num) {
    // Numbers less than or equal to 0 cannot be perfect numbers
    if (num <= 0) {
        return 0;
    }

    int sum = 0;

    // Loop to find proper divisors up to num / 2
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; // Add divisor to sum
        }
    }

    // If sum of proper divisors equals the original number, it is perfect
    return (sum == num);
}
