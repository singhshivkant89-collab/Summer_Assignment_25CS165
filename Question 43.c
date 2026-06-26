#include <stdio.h>
#include <stdbool.h> // Required for using true and false in C

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than or equal to 1 are not prime
    if (n <= 1) {
        return false;
    }

    // Check for factors from 2 up to the square root of n (i * i <= n)
    for (int i = 2; i * i <= n; i++) {
        // If n is divisible by any i, it is not prime
        if (n % i == 0) {
            return false;
        }
    }

    // If no factors were found, the number is prime
    return true;
}

int main() {
    int num;

    // Ask user for input
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the function and print the result
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
