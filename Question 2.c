#include <stdio.h>

int main() {
    int num;

    // Take input from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Multiplication Table of %d:\n", num);

    // Loop from 1 to 10 to print the table
    for (int i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}