#include <stdio.h>
#include <ctype.h> // Required for isspace()

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; // State tracker: 0 means outside a word, 1 means inside a word

    while (*str) {
        // isspace() checks for ' ', '\t', '\n', '\v', '\f', and '\r'
        if (isspace((unsigned char)*str)) {
            in_word = 0; // We hit whitespace, so we are no longer in a word
        } 
        // If the character is not whitespace and we weren't already in a word
        else if (in_word == 0) {
            in_word = 1; // Mark that we entered a word
            count++;     // Increment the word counter
        }
        str++; // Move to the next character
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    // fgets is used instead of scanf to safely read spaces and prevent buffer overflows
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int words = count_words(sentence);
        printf("The number of words in the sentence: %d\n", words);
    }

    return 0;
}
