#include <stdio.h>

int main() {
    int i, j;
    
    // Outer loop controls the number of rows
    for (i = 1; i <= 5; i++) {
        // Inner loop prints the number 'i' exactly 'i' times
        for (j = 1; j <= i; j++) {
            printf("%d", i);
        }
        // Move to the next line after each row
        printf("\n");
    }
    
    return 0;
}
