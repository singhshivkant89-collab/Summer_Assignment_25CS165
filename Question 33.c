#include <stdio.h>

int main() {
    int n = 5;

    // Outer loop for rows
    for (int i = n; i >= 1; i--) {
        // Inner loop for printing stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
    return 0;
}
