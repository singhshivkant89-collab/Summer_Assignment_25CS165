#include <stdio.h>

int main() {
    double base, result = 1.0;
    int exponent, i;

    // Get input from user
    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (n): ");
    scanf("%d", &exponent);

    // Handle negative exponents
    int positive_exponent = (exponent < 0) ? -exponent : exponent;

    // Multiply base 'positive_exponent' times
    for (i = 1; i <= positive_exponent; i++) {
        result *= base;
    }

    // If original exponent was negative, invert the final result
    if (exponent < 0) {
        result = 1.0 / result;
    }

    printf("%.2lf^%d = %.6lf\n", base, exponent, result);

    return 0;
}
