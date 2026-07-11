#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[100][100];
    int isSymmetric = 1; // Flag variable: 1 means symmetric, 0 means not symmetric

    // 1. Get dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // 2. A symmetric matrix must always be a square matrix
    if (rows != cols) {
        printf("\nThe matrix is NOT symmetric (It must be a square matrix).\n");
        return 0;
    }

    // 3. Input matrix elements
    printf("\nEnter elements of the matrix (%dx%d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Check for symmetry by comparing index [i][j] with [j][i]
    // Optimisation: Only check elements above the main diagonal (j > i)
    for (i = 0; i < rows; i++) {
        for (j = i + 1; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch
                break;
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }

    // 5. Print original matrix for clarity
    printf("\nYour Entered Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // 6. Output result
    if (isSymmetric == 1) {
        printf("\nResult: The matrix is a SYMMETRIC matrix.\n");
    } else {
        printf("\nResult: The matrix is NOT a symmetric matrix.\n");
    }

    return 0;
}
