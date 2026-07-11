#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    // Array to store frequencies of all 256 possible ASCII characters
    int freq[256] = {0}; 
    int i;

    printf("Enter a string: ");
    // Safely read input including spaces, up to MAX_SIZE - 1
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    // Step 1: Traverse the string and increment the count for each character
    for (i = 0; str[i] != '\0'; i++) {
        // Exclude the trailing newline character added by fgets
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;
        }
    }

    // Step 2: Print only the characters that appeared at least once
    printf("\nCharacter Frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            // Handle space visibility for clear output layout
            if (i == ' ') {
                printf("Space ' ' occurs %d times\n", freq[i]);
            } else {
                printf("'%c' occurs %d times\n", i, freq[i]);
            }
        }
    }

    return 0;
}
