#include <stdio.h>

// Function declaration (prototype)
int findSum(int num1, int num2);

int main() {
    int a, b, result;

    // Taking user input
    printf("Enter first number: ");
    scanf("%d", &a);
    
    printf("Enter second number: ");
    scanf("%d", &b);

    // Function call
    result = findSum(a, b);

    // Displaying the result
    printf("The sum of %d and %d is: %d\n", a, b, result);

    return 0;
}

// Function definition to find the sum
int findSum(int num1, int num2) {
    return num1 + num2;
}
