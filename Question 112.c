#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures and maximum limits
#define FILE_NAME "contacts.txt"
#define MAX_LIMIT 50

typedef struct {
    char name[MAX_LIMIT];
    char phone[MAX_LIMIT];
    char email[MAX_LIMIT];
} Contact;

// Function prototypes
void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
void flushInput();

int main() {
    int choice;

    while (1) {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            flushInput();
            continue;
        }
        flushInput(); // Clear newline character from buffer

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Clear input buffer to prevent infinite loops with string scanning
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Create: Add a new contact to the text file
void addContact() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact newContact;
    
    printf("Enter Name: ");
    fgets(newContact.name, MAX_LIMIT, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter Phone Number: ");
    fgets(newContact.phone, MAX_LIMIT, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(newContact.email, MAX_LIMIT, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    // Append structural data safely using format spacing
    fprintf(fp, "%s,%s,%s\n", newContact.name, newContact.phone, newContact.email);
    fclose(fp);

    printf("Contact added successfully!\n");
}

// 2. Read: Display all stored contacts
void viewContacts() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No contacts found. The file is empty or missing.\n");
        return;
    }

    char line[200];
    int count = 1;
    
    printf("\n---------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-20s\n", "S.No", "Name", "Phone", "Email");
    printf("---------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp)) {
        char name[MAX_LIMIT], phone[MAX_LIMIT], email[MAX_LIMIT];
        
        // Parse CSV format
        sscanf(line, "%[^,],%[^,],%[^\n]", name, phone, email);
        printf("%-5d %-20s %-15s %-20s\n", count++, name, phone, email);
    }
    
    if(count == 1) {
        printf("No records found.\n");
    }
    printf("---------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search: Find a contact by name
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No records found to search.\n");
        return;
    }

    char searchName[MAX_LIMIT];
    char line[200];
    int found = 0;

    printf("Enter the Name to search: ");
    fgets(searchName, MAX_LIMIT, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        char name[MAX_LIMIT], phone[MAX_LIMIT], email[MAX_LIMIT];
        sscanf(line, "%[^,],%[^,],%[^\n]", name, phone, email);

        // Case-insensitive check can be substituted with strcasecmp if available
        if (strcmp(name, searchName) == 0) {
            printf("\nContact Found:\n");
            printf("Name : %s\n", name);
            printf("Phone: %s\n", phone);
            printf("Email: %s\n", email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact matching '%s' not found.\n", searchName);
    }
    fclose(fp);
}

// 4. Update: Modify existing contact details
void editContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *tempFp = fopen("temp.txt", "w");
    
    if (fp == NULL || tempFp == NULL) {
        printf("Error opening file assets!\n");
        return;
    }

    char searchName[MAX_LIMIT];
    char line[200];
    int found = 0;

    printf("Enter the Name of the contact you want to edit: ");
    fgets(searchName, MAX_LIMIT, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        char name[MAX_LIMIT], phone[MAX_LIMIT], email[MAX_LIMIT];
        sscanf(line, "%[^,],%[^,],%[^\n]", name, phone, email);

        if (strcmp(name, searchName) == 0) {
            found = 1;
            Contact updated;
            printf("Contact matching found! Enter new details:\n");
            
            printf("Enter New Name: ");
            fgets(updated.name, MAX_LIMIT, stdin);
            updated.name[strcspn(updated.name, "\n")] = '\0';

            printf("Enter New Phone Number: ");
            fgets(updated.phone, MAX_LIMIT, stdin);
            updated.phone[strcspn(updated.phone, "\n")] = '\0';

            printf("Enter New Email: ");
            fgets(updated.email, MAX_LIMIT, stdin);
            updated.email[strcspn(updated.email, "\n")] = '\0';

            fprintf(tempFp, "%s,%s,%s\n", updated.name, updated.phone, updated.email);
        } else {
            fprintf(tempFp, "%s", line);
        }
    }

    fclose(fp);
    fclose(tempFp);

    // Swap original file with updated temp file
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Contact modified successfully!\n");
    } else {
        printf("Contact matching '%s' not found.\n", searchName);
    }
}

// 5. Delete: Remove a contact from file records
void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *tempFp = fopen("temp.txt", "w");

    if (fp == NULL || tempFp == NULL) {
        printf("Error opening data targets!\n");
        return;
    }

    char searchName[MAX_LIMIT];
    char line[200];
    int found = 0;

    printf("Enter the Name of the contact to delete: ");
    fgets(searchName, MAX_LIMIT, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        char name[MAX_LIMIT], phone[MAX_LIMIT], email[MAX_LIMIT];
        sscanf(line, "%[^,],%[^,],%[^\n]", name, phone, email);

        if (strcmp(name, searchName) == 0) {
            found = 1; // Skip writing this line to exclude it
            continue;
        }
        fprintf(tempFp, "%s", line);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Contact removed permanently!\n");
    } else {
        printf("No contact found matching '%s'.\n", searchName);
    }
}
