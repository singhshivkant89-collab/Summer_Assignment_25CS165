#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

// Function to find the maximum occurring character
char getMaxOccurringChar(char* str, int* maxCount) {
    // Create an array to keep the count of individual characters
    int count[ASCII_SIZE] = {0};

    // Construct character count array from the input string
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        // Cast to unsigned char to safely handle negative values if any
        count[(unsigned char)str[i]]++;
    }

    int max = -1; 
    char result = '\0';

    // Traverse the string to find the maximum occurring character
    // This approach naturally picks the first one in case of a tie
    for (int i = 0; i < len; i++) {
        if (count[(unsigned char)str[i]] > max) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }

    *maxCount = max;
    return result;
}

int main() {
    char str[100];
    int count = 0;

    printf("Enter a string: ");
    // Using fgets instead of gets() to prevent buffer overflow
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Check if the input string is empty
    if (strlen(str) == 0) {
        printf("The string is empty.\n");
        return 0;
    }

    char maxChar = getMaxOccurringChar(str, &count);

    printf("The maximum occurring character is '%c' (appears %d times).\n", maxChar, count);

    return 0;
}
