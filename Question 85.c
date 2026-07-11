#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    // Handle newline character if input is read using fgets
    if (str[right] == '\n') {
        str[right] = '\0';
        right--;
    }

    // Compare characters from both ends moving towards the center
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Mismatch found, not a palindrome
        }
        left++;
        right--;
    }
    return true; // All characters matched
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Using fgets instead of scanf to handle inputs safely
    fgets(str, sizeof(str), stdin);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
