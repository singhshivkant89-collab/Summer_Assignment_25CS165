#include <stdio.h>

// Function helper to check if a single number is prime
int isPrime(int num) {
    // Numbers less than or equal to 1 are not prime
    if (num <= 1) {
        return 0; 
    }
    
    // Check divisibility from 2 up to the square root of the number (i * i <= num)
    // This optimization vastly improves performance compared to checking up to num - 1
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Number is divisible, so it is not prime
        }
    }
    return 1; // Number is prime
}

int main() {
    int lower, upper, temp;

    // Read range boundaries from the user
    printf("Enter lower bound of the range: ");
    scanf("%d", &lower);
    
    printf("Enter upper bound of the range: ");
    scanf("%d", &upper);

    // Auto-correct if the user types the larger number first
    if (lower > upper) {
        temp = lower;
        lower = upper;
        upper = temp;
    }

    printf("\nPrime numbers between %d and %d are:\n", lower, upper);

    // Iterate through the range and check each number
    int found_prime = 0;
    for (int i = lower; i <= upper; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found_prime = 1;
        }
    }

    if (!found_prime) {
        printf("None found in this range.");
    }

    printf("\n");
    return 0;
}