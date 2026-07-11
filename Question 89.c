#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

// Function to find the first non-repeating character
char findFirstNonRepeating(const char *str) {
    int freq[MAX_CHAR] = {0}; // Initialize frequency of all characters to 0
    
    // Step 1: Count frequency of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    // Step 2: Scan the string again to find the first character with frequency 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i]; // Return the first unique character found
        }
    }
    
    return '\0'; // Return null character if no unique character exists
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    // Reads input string, including spaces, up to 99 characters
    if (fgets(str, sizeof(str), stdin)) {
        // Remove trailing newline character added by fgets
        str[strcspn(str, "\n")] = '\0';
        
        char result = findFirstNonRepeating(str);
        
        if (result != '\0') {
            printf("The first non-repeating character is: '%c'\n", result);
        } else {
            printf("All characters are repeating or the string is empty.\n");
        }
    }
    
    return 0;
}
