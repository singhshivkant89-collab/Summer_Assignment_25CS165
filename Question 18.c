#include <stdio.h>

// Function to calculate factorial of a digit
int calculate_factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num, temp, digit, sum = 0;

    printf("Enter a number to check: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Copy the original number to a temporary variable
    temp = num;

    // Extract digits and sum up their factorials
    while (temp > 0) {
        digit = temp % 10;
        sum += calculate_factorial(digit);
        temp /= 10;
    }

    // Verify if it is a strong number
    if (sum == num) {
        printf("%d is a Strong Number.\n", num);
    } else {
        printf("%d is NOT a Strong Number.\n", num);
    }

    return 0;
}