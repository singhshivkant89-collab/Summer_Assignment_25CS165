#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int i, j, rowSum;

    // Ask user for matrix dimensions
    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    // Input matrix elements
    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("\nThe entered matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and print row-wise sum
    printf("\nRow-wise sum:\n");
    for (i = 0; i < rows; i++) {
        rowSum = 0; // Reset sum for each new row
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}
