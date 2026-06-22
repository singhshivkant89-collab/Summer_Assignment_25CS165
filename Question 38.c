#include <stdio.h>

int main() {
    int rows, i, j, space;

    // Ask user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop handles the number of rows
    for (i = 1; i <= rows; i++) {
        
        // First inner loop prints the leading spaces
        for (space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // Second inner loop prints the odd number of stars (2*i - 1)
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        // Move to the next line after printing each row
        printf("\n");
    }

    return 0;
}
