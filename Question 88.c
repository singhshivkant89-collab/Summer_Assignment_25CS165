#include <stdio.h>

// Function to remove all spaces from a string in-place
void removeSpaces(char *str) {
    int readIndex = 0;
    int writeIndex = 0;

    // Loop until the end of the string
    while (str[readIndex] != '\0') {
        // If the current character is not a space, copy it
        if (str[readIndex] != ' ') {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    
    // Add the null terminator to mark the new end of the string
    str[writeIndex] = '\0';
}

int main() {
    // Character array initialized with spaces
    char text[] = " C   p r o g r a m m i n g  ";

    printf("Original: '%s'\n", text);

    // Call the function to remove spaces
    removeSpaces(text);

    printf("Modified: '%s'\n", text);

    return 0;
}
