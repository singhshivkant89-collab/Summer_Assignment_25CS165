#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if str2 is a rotation of str1
bool areRotations(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are not equal, they cannot be rotations
    if (len1 != len2) {
        return false;
    }

    // Allocate memory for the concatenated string (len1 * 2 + 1 for '\0')
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }

    // Copy str1 into temp and concatenate str1 to it again
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of temp
    // strstr returns a pointer if found, or NULL if not found
    char *match_ptr = strstr(temp, str2);

    // Free the dynamically allocated memory
    free(temp);

    // If match_ptr is not NULL, str2 is a rotation
    return (match_ptr != NULL);
}

int main() {
    char str1[] = "AACD";
    char str2[] = "ACDA";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    if (areRotations(str1, str2)) {
        printf("Result: Strings are rotations of each other.\n");
    } else {
        printf("Result: Strings are NOT rotations of each other.\n");
    }

    return 0;
}
