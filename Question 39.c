#include <stdio.h>

int main() {
    int rows = 5; // You can change this to any number of rows

    for (int i = 1; i <= rows; i++) {
        // 1. Print leading spaces for alignment
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // 2. Print the increasing part of the numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 3. Print the decreasing part of the numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
