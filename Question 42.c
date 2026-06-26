#include <stdio.h>

// Function declaration/prototype
int findMaximum(int num1, int num2);

int main() {
    int a, b, max;

    // Asking for user input
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Calling the function and storing the returned value
    max = findMaximum(a, b);

    // Displaying the result
    printf("The maximum number is: %d\n", max);

    return 0;
}

/**
 * Function to find the maximum between two integers.
 * @param num1 First integer
 * @param num2 Second integer
 * @return The larger of the two integers
 */
int findMaximum(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}
