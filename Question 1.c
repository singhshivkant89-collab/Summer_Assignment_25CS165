#include <stdio.h>

int main() {
    int n, sum;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    // Using formula to calculate sum
    sum = n * (n + 1) / 2;
    
    printf("The sum of first %d natural numbers is: %d\n", n, sum);
    return 0;
}