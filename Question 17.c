#include <stdio.h>

int main() {
    int num, i, sum = 0;

    // Ask the user to enter a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Core logic: Numbers less than or equal to 0 cannot be perfect numbers
    if (num <= 0) {
        printf("%d is not a perfect number.\n", num);
        return 0;
    }

    // Find all proper divisors and calculate their sum
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Compare the sum of divisors with the original number
    if (sum == num) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}