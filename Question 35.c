#include <stdio.h>

int main() {
    int i, j;
    int rows = 5;
    char ch = 'A';

    // Outer loop handles the number of rows
    for (i = 1; i <= rows; i++) {
        
        // Inner loop prints the same character 'i' times
        for (j = 1; j <= i; j++) {
            printf("%c", ch);
        }
        
        // Move to the next line after printing a row
        printf("\n");
        
        // Increment the character to the next letter
        ch++;
    }

    return 0;
}
