#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[256];
    
    printf("Enter a sentence: ");
    // Safely read standard input including spaces, then remove trailing newline
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }
    sentence[strcspn(sentence, "\n")] = '\0';

    int i = 0;
    int current_len = 0;
    int max_len = 0;
    int longest_start_idx = 0;

    // Loop through each character including the terminating null character
    while (1) {
        // A character is part of a word if it is alphanumeric
        if (isalnum((unsigned char)sentence[i])) {
            current_len++;
        } else {
            // We hit a delimiter (space, punctuation, or end of string)
            if (current_len > max_len) {
                max_len = current_len;
                // Calculate where this longest word began
                longest_start_idx = i - current_len;
            }
            current_len = 0; // Reset length counter for the next word
        }

        // Break out of the loop after checking the null terminator
        if (sentence[i] == '\0') {
            break;
        }
        i++;
    }

    // Print the results safely using maximum length precision
    if (max_len > 0) {
        printf("The longest word is: %.*s\n", max_len, &sentence[longest_start_idx]);
        printf("Length: %d\n", max_len);
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}
