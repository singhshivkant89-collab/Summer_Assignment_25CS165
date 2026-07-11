#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int a[10][10], b[10][10], result[10][10];

    // Input dimensions for the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Input dimensions for the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if matrix multiplication is possible
    if (c1 != r2) {
        printf("Error! Columns of the first matrix must equal rows of the second matrix.\n");
        return 0;
    }

    // Input elements for the first matrix
    printf("\nEnter elements of the first matrix:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements of the second matrix:\n");
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize result matrix elements to 0
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiply the two matrices using 3 nested loops
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the result
    printf("\nResultant Multiplied Matrix:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
