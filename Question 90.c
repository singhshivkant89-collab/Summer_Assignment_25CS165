#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 // Total possible ASCII characters

// Function to find the first repeating character
char findFirstRepeating(char *str) {
    // Array to store the frequency/count of characters
    int count[MAX_CHAR] = {0};

    // Traverse the string from left to right
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        // If the character is already seen, it is the first repeating one
        if (count[ch] == 1) {
            return str[i];
        }
        
        // Mark the character as seen
        count[ch]++;
    }

    // Return null terminator if no character repeats
    return '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Reads input string including spaces until a newline is hit
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove trailing newline character added by fgets
        str[strcspn(str, "\n")] = '\0';
    }

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}
