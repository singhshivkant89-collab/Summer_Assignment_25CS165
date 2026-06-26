#include <stdio.h>
#include <math.h>

// Function declaration
int isArmstrong(int num);

int main() {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the function and check the result
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum, remainder, digits = 0, sum = 0;

    originalNum = num;

    // 1. Count the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        digits++;
    }

    originalNum = num;

    // 2. Calculate the sum of power of individual digits
    while (originalNum != 0) {
        remainder = originalNum % 10;
        
        // Use round() to avoid floating-point inaccuracies with pow()
        sum += (int)round(pow(remainder, digits));
        
        originalNum /= 10;
    }

    // 3. Return 1 (true) if the sum matches original number, else 0 (false)
    return (sum == num);
}
