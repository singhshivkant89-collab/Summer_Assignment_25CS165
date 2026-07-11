#include <stdio.h>
#include <string.h>

// Function to compress the input string
void compressString(const char *input, char *output) {
    int i = 0;
    int j = 0; // Index for output string
    int len = strlen(input);

    while (i < len) {
        int count = 1;
        
        // Count consecutive occurrences of the current character
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append character to output
        output[j++] = input[i];

        // Append the count to the output string
        // sprintf handles multi-digit numbers safely (e.g., 10, 12, etc.)
        j += sprintf(&output[j], "%d", count);

        i++;
    }
    
    // Null-terminate the compressed output string
    output[j] = '\0';
}

int main() {
    char inputString[100];
    char compressedString[200]; // Allocation size handles worst-case expansions

    printf("Enter a string to compress: ");
    // Read input string, including spaces if any
    fgets(inputString, sizeof(inputString), stdin);
    
    // Remove trailing newline character added by fgets
    inputString[strcspn(inputString, "\n")] = '\0';

    // Check for empty string edge case
    if (strlen(inputString) == 0) {
        printf("Compressed String: (empty)\n");
        return 0;
    }

    // Perform compression
    compressString(inputString, compressedString);

    // Print result
    printf("Original String  : %s\n", inputString);
    printf("Compressed String: %s\n", compressedString);

    return 0;
}
