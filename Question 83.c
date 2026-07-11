#include <stdio.h>
#include <ctype.h> // Required for isalpha() and tolower()

int main() {
    char str[150];
    int vowels = 0;
    int consonants = 0;

    // Get full line of string input safely from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Loop through each character of the string until the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        
        // Process only if the character is an alphabet letter
        if (isalpha(str[i])) {
            
            // Convert to lowercase to minimize comparison checks
            char lower_ch = tolower(str[i]);

            // Check if the character is a vowel
            if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || 
                lower_ch == 'o' || lower_ch == 'u') {
                vowels++;
            } 
            // If it's an alphabet letter but not a vowel, it's a consonant
            else {
                consonants++;
            }
        }
    }

    // Display final counts
    printf("\n--- Results ---\n");
    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);

    return 0;
}
