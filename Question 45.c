#include <stdio.h>

int main() {
    int num, reversed = 0, remainder, original;

    // Get user input
    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;  // Store the original number

    // Reverse the number using a for loop
    for (; num != 0; num /= 10) {
        remainder = num % 10;  // Get the last digit
        reversed = reversed * 10 + remainder;  // Build the reversed number
    }

    // Check if the number is a palindrome
    if (original == reversed) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }

    return 0;
}