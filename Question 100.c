#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int main() {
    char sentence[500];
    char words[MAX_WORDS][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int wordCount = 0;

    // 1. Accept input string from the user
    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    // Remove the trailing newline character added by fgets
    sentence[strcspn(sentence, "\n")] = '\0';

    // 2. Tokenize the sentence into separate words
    char *token = strtok(sentence, " ,.-!?");
    while (token != NULL && wordCount < MAX_WORDS) {
        strncpy(words[wordCount], token, MAX_LENGTH - 1);
        words[wordCount][MAX_LENGTH - 1] = '\0'; // Ensure null-termination
        wordCount++;
        token = strtok(NULL, " ,.-!?");
    }

    // 3. Sort words by length using Bubble Sort
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            // Compare lengths of adjacent words
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap the words if the current one is longer than the next
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    // 4. Output the sorted list
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s (length: %lu)\n", words[i], (unsigned long)strlen(words[i]));
    }

    return 0;
}
