#include <stdio.h>

int main() {
    long long num;
    int count = 0;

    // Request an integer from the user
    printf("Enter an integer: ");
    scanf("%lld", &num);

    // Using a do-while loop to handle the number 0 correctly
    do {
        count++;
        num /= 10; // Removes the last digit
    } while (num != 0);

    printf("Total number of digits: %d\n", count);

    return 0;
}