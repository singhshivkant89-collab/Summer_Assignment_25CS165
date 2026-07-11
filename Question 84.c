#include <stdio.h>
#include <ctype.h> // Required for toupper()

int main() {
    char str[100];

    printf("Enter a string in lowercase: ");
    // Safely read a line of text including spaces
    fgets(str, sizeof(str), stdin); 

    // Loop through each character until the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }

    printf("Uppercase string: %s", str);

    return 0;
}
