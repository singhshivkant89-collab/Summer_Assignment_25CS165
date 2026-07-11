#include <stdio.h>
#include <stdlib.h>

// Function declarations for better structure
void displayMenu();
void performCalculation(int choice);

int main() {
    int choice;

    // Continuous loop to keep the calculator running
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        
        // Validate that input is a valid integer
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid input format. Please enter a number.\n\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            performCalculation(choice);
        } else if (choice == 5) {
            printf("\nExiting the calculator. Goodbye!\n");
        } else {
            printf("\nInvalid option! Please pick a number between 1 and 5.\n\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to print the user options
void displayMenu() {
    printf("=============================\n");
    printf("    MENU-DRIVEN CALCULATOR   \n");
    printf("=============================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

// Function to safely execute calculations
void performCalculation(int choice) {
    double num1, num2, result;

    printf("Enter first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Invalid number entered.\n\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Invalid number entered.\n\n");
        while (getchar() != '\n');
        return;
    }

    // Switch case to process calculations based on user input
    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("\nResult: %.2lf + %.2lf = %.2lf\n\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\nResult: %.2lf - %.2lf = %.2lf\n\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\nResult: %.2lf * %.2lf = %.2lf\n\n", num1, num2, result);
            break;
        case 4:
            // Check to prevent division by zero runtime errors
            if (num2 == 0) {
                printf("\nError: Division by zero is undefined!\n\n");
            } else {
                result = num1 / num2;
                printf("\nResult: %.2lf / %.2lf = %.2lf\n\n", num1, num2, result);
            }
            break;
        default:
            printf("\nAn unexpected error occurred.\n\n");
    }
}
