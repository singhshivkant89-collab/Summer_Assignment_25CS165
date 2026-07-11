#include <stdio.h>
#include <stdbool.h>

// Function declarations to keep code structured
void showMenu();
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    // Initializing tracking variables 
    int defaultPin = 1234;
    int enteredPin;
    int pinAttempts = 0;
    const int MAX_ATTEMPTS = 3;
    double accountBalance = 5000.00; // Starting default balance
    int choice;
    bool isRunning = true;

    printf("=== WELCOME TO THE ATM SIMULATION SYSTEM ===\n");

    // PIN Authentication loop (Maximum 3 attempts allowed)
    while (pinAttempts < MAX_ATTEMPTS) {
        printf("\nPlease enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input type. Please enter numbers only.\n");
            while (getchar() != '\n'); // Clear input buffer
            pinAttempts++;
            continue;
        }

        if (enteredPin == defaultPin) {
            printf("\nVerification Successful! Access Granted.\n");
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", MAX_ATTEMPTS - pinAttempts);
        }
    }

    // Terminate if user fails authentication too many times
    if (pinAttempts == MAX_ATTEMPTS) {
        printf("\nToo many incorrect attempts. Your card has been blocked.\n");
        return 0; 
    }

    // Main ATM Operation Interface
    while (isRunning) {
        showMenu();
        printf("Choose an option (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Please select a valid numerical option.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(accountBalance);
                break;
            case 2:
                accountBalance = depositMoney(accountBalance);
                break;
            case 3:
                accountBalance = withdrawMoney(accountBalance);
                break;
            case 4:
                printf("\nThank you for using our ATM services. Goodbye!\n");
                isRunning = false;
                break;
            default:
                printf("Invalid selection. Please choose an option from the menu.\n");
        }
    }

    return 0;
}

// Function to print the operational options
void showMenu() {
    printf("\n---------- ATM MENU ----------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

// Function to handle balance inquiries
void checkBalance(double balance) {
    printf("\nYour current account balance is: $%.2f\n", balance);
}

// Function to handle deposits
double depositMoney(double balance) {
    double depositAmount;
    printf("\nEnter the amount to deposit: $");
    scanf("%u", &depositAmount); // Reading deposit as positive numerical values

    if (depositAmount <= 0) {
        printf("Error: Invalid deposit amount.\n");
    } else {
        balance += depositAmount;
        printf("Successfully deposited $%.2f. New Balance: $%.2f\n", depositAmount, balance);
    }
    return balance;
}

// Function to handle cash withdrawals safely
double withdrawMoney(double balance) {
    double withdrawAmount;
    printf("\nEnter the amount to withdraw: $");
    scanf("%u", &withdrawAmount);

    if (withdrawAmount <= 0) {
        printf("Error: Invalid withdrawal amount.\n");
    } else if (withdrawAmount > balance) {
        printf("Error: Insufficient funds. Your balance is $%.2f\n", balance);
    } else {
        balance -= withdrawAmount;
        printf("Successfully withdrew $%.2f. Remaining Balance: $%.2f\n", withdrawAmount, balance);
    }
    return balance;
}
