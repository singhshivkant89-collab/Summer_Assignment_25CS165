#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // Ask user for matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the entered matrix
    printf("\nThe Matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");

    // Logic to find column-wise sum
    // Outer loop targets each column, inner loop traverses its rows
    for (j = 0; j < cols; j++) {
        int colSum = 0; 
        for (i = 0; i < rows; i++) {
            colSum += matrix[i][j]; 
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
