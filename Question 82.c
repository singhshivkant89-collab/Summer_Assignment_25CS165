#include <stdio.h>
#include <string.h>

// Function to reverse the string in place
void reverseString(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Swap characters from both ends until pointers meet
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Securely read string including spaces
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character added by fgets, if present
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
