#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if two strings are anagrams
int check_anagram(char str1[], char str2[]) {
    int count[256] = {0}; // Frequency array for all ASCII characters
    int i;

    // If lengths are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    // Increment count for first string, decrement for second string
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    // If all frequencies are zero, the strings are anagrams
    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0; // Mismatch found
        }
    }

    return 1; // It is an anagram
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter the first string: ");
    // Read string including spaces (stops at newline)
    scanf("%99[^\n]", str1);
    
    // Clear the input buffer before reading the next string
    while (getchar() != '\n');

    printf("Enter the second string: ");
    scanf("%99[^\n]", str2);

    // Call function and display the output
    if (check_anagram(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }

    return 0;
}
