#include <stdio.h>

int main() {
    int decimalNumber;
    int binaryArray[32];
    int index = 0;

    // Prompt the user for input
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Handle the special case where the input is 0
    if (decimalNumber == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    // Step-by-step conversion logic
    while (decimalNumber > 0) {
        binaryArray[index] = decimalNumber % 2; // Store the remainder (0 or 1)
        decimalNumber = decimalNumber / 2;     // Divide the quotient by 2
        index++;                                // Move to the next array position
    }

    // Print the binary elements in reverse order
    printf("Binary equivalent: ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binaryArray[j]);
    }
    printf("\n");

    return 0;
}