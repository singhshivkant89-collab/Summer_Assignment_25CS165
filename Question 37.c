#include <stdio.h>

int main() {
    int rows, i, j;

    // Ask user for the number of pyramid rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop handles the number of rows
    for (i = 1; i <= rows; i++) {
        
        // Inner loop 1: Prints the leading spaces for alignment
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Inner loop 2: Prints the required number of stars (*)
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
