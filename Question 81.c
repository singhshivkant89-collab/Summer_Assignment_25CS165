#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    // fgets reads spaces safely without causing buffer overflows
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if it was captured by fgets
    while (str[length] != '\0') {
        if (str[length] == '\n') {
            str[length] = '\0';
            break;
        }
        length++;
    }

    printf("Length of the string is: %d\n", length);

    return 0;
}
