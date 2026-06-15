#include <stdio.h>

int main() {
    int n;
    // Use long long to handle larger Fibonacci numbers without overflow
    unsigned long long first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // The first two terms are 0 and 1
        } else {
            next = first + second; // Calculate the next term
            first = second;        // Shift variables forward
            second = next;
        }
        printf("%llu ", next);
    }

    printf("\n");
    return 0;
}