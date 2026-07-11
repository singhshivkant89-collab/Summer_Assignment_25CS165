#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to store bank account details
typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

// Global array to hold accounts and a counter
Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
int findAccount(int accNum);

int main() {
    int choice;

    do {
        printf("\n=== BANK ACCOUNT SYSTEM ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nThank you for using our banking system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to safely create a new account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nError: Bank system capacity reached. Cannot create more accounts.\n");
        return;
    }

    int accNum;
    printf("\nEnter desired Account Number: ");
    scanf("%d", &accNum);

    // Check if the account number already exists
    if (findAccount(accNum) != -1) {
        printf("Error: Account number %d already exists!\n", accNum);
        return;
    }

    accounts[totalAccounts].accountNumber = accNum;

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", accounts[totalAccounts].name); // Reads strings with spaces

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &accounts[totalAccounts].balance);

    if (accounts[totalAccounts].balance < 0) {
        printf("Error: Initial deposit cannot be negative. Account creation failed.\n");
        return;
    }

    printf("\nAccount successfully created for %s!\n", accounts[totalAccounts].name);
    totalAccounts++;
}

// Function to deposit money into a specific account
void depositMoney() {
    int accNum, index;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nSuccess! Deposited $%.2f. New Balance: $%.2f\n", amount, accounts[index].balance);
}

// Function to withdraw money safely
void withdrawMoney() {
    int accNum, index;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Error: Insufficient funds! Current balance is $%.2f\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    printf("\nSuccess! Withdrew $%.2f. New Balance: $%.2f\n", amount, accounts[index].balance);
}

// Function to lookup and display account details
void checkBalance() {
    int accNum, index;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    index = findAccount(accNum);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    printf("Account Number : %d\n", accounts[index].accountNumber);
    printf("Account Holder : %s\n", accounts[index].name);
    printf("Current Balance: $%.2f\n", accounts[index].balance);
}

// Helper utility to search for an account index using its number
int findAccount(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i; // Returns the actual array index location
        }
    }
    return -1; // Indicates account not found
}
