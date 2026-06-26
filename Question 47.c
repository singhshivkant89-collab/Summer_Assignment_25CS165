#include <stdio.h>

// Function to print Fibonacci series up to n terms
void printFibonacciIterative(int n) {
    if (n <= 0) {
        printf("Please enter a number greater than 0.\n");
        return;
    }

    int t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int terms = 10; // Change this value to print more or fewer terms
    printFibonacciIterative(terms);
    return 0;
}
