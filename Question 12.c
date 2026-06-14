#include <stdio.h>

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int find_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the Least Common Multiple (LCM)
int find_lcm(int a, int b) {
    // Handling negative inputs by converting them to absolute values
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    // If either number is 0, LCM is 0
    if (a == 0 || b == 0) {
        return 0;
    }

    // Formula: LCM = (a * b) / GCD
    // Dividing first prevents potential integer overflow
    return (a / find_gcd(a, b)) * b;
}

int main() {
    int num1, num2, lcm;

    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    lcm = find_lcm(num1, num2);

    printf("The LCM of %d and %d is %d\n", num1, num2, lcm);

    return 0;
}