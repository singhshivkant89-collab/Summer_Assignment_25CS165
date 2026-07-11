#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    // Hash array to keep track of seen characters (ASCII size 256)
    int seen[256] = {0};
    
    int readIndex = 0;
    int writeIndex = 0;
    
    // Process the string until the null-terminator
    while (str[readIndex] != '\0') {
        unsigned char ch = str[readIndex];
        
        // If the character has not been seen yet
        if (seen[ch] == 0) {
            seen[ch] = 1;              // Mark as seen
            str[writeIndex] = str[readIndex]; // Copy character to write position
            writeIndex++;              // Advance write position
        }
        readIndex++; // Always advance read position
    }
    
    // Null-terminate the filtered string
    str[writeIndex] = '\0';
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    // Safe alternative to gets() which prevents buffer overflow
    if (fgets(str, sizeof(str), stdin) != NULL) {
        
        // Remove trailing newline character added by fgets if present
        str[strcspn(str, "\n")] = '\0';
        
        printf("Original string: %s\n", str);
        
        removeDuplicates(str);
        
        printf("String after removing duplicates: %s\n", str);
    }
    
    return 0;
}
