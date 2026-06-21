#include <stdio.h>

int main() {
    int rows = 5; // Change this to set the number of rows

    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
