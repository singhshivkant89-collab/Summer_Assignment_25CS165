#include <stdio.h>

// Function to calculate GCD using Euclidean Algorithm
int findGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int num1, num2;

    // Taking user input
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert negative numbers to positive
    int absNum1 = (num1 < 0) ? -num1 : num1;
    int absNum2 = (num2 < 0) ? -num2 : num2;

    int result = findGCD(absNum1, absNum2);

    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}