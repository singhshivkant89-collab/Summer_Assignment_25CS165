#include <stdio.h>

int main() {
    int num;
    unsigned long long fact = 1;

    // Get input from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Error handling for negative numbers
    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        // Loop to multiply numbers from 1 to num
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", num, fact);
    }

    return 0;
}