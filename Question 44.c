#include <stdio.h>

// Function declaration
unsigned long long findFactorial(int n);

int main() {
    int num;
    unsigned long long result;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check for negative numbers
    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else if (num > 20) {
        printf("Error: Result too large to store in standard integer types (Max 20).\n");
    } else {
        result = findFactorial(num);
        printf("Factorial of %d = %llu\n", num, result);
    }

    return 0;
}

// Function definition using a loop
unsigned long long findFactorial(int n) {
    unsigned long long fact = 1;
    
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    
    return fact;
}
