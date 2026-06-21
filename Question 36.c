#include <stdio.h>

int main() {
    int i, j, size;

    // Get the size of the square from the user
    printf("Enter the size of the square: ");
    scanf("%d", &size);

    // Outer loop to handle the number of rows
    for (i = 1; i <= size; i++) {
        // Inner loop to handle the columns in each row
        for (j = 1; j <= size; j++) {
            // Print star only for boundaries (first/last row or first/last column)
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
            } else {
                // Print space for the hollow inner region
                printf(" ");
            }
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
