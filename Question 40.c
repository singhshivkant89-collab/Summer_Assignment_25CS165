#include <stdio.h>

int main() {
    int rows = 5; // Total number of rows in the pyramid

    // Outer loop handles the rows
    for (int i = 1; i <= rows; i++) {
        
        // 1. Inner loop to print leading whitespace
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // 2. Inner loop to print characters in ascending order (e.g., A -> B -> C)
        for (int j = 1; j <= i; j++) {
            printf("%c", 'A' + j - 1);
        }

        // 3. Inner loop to print characters in descending order (e.g., B -> A)
        for (int j = i - 1; j >= 1; j--) {
            printf("%c", 'A' + j - 1);
        }

        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
