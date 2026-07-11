#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Structure to define an inventory item
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Global variables
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function Prototypes
void menu();
void addItem();
void viewInventory();
void updateItem();
void deleteItem();
void searchItem();
int findItemIndexById(int id);
void clearInputBuffer();

int main() {
    int choice;

    do {
        menu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: updateItem(); break;
            case 4: deleteItem(); break;
            case 5: searchItem(); break;
            case 6: printf("\nExiting program. Thank you!\n"); break;
            default: printf("\n[!] Invalid option. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Displays the main user interface menu
void menu() {
    printf("\n====================================");
    printf("\n     INVENTORY MANAGEMENT SYSTEM    ");
    printf("\n====================================");
    printf("\n1. Add New Item");
    printf("\n2. View All Items");
    printf("\n3. Update Item Stock/Price");
    printf("\n4. Delete Item");
    printf("\n5. Search Item by ID");
    printf("\n6. Exit");
    printf("\n====================================\n");
}

// Adds a new unique item to the inventory array
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\n[!] Inventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter Unique Item ID (Integer): ");
    if (scanf("%d", &newItem.id) != 1) {
        printf("[!] Invalid ID format.\n");
        clearInputBuffer();
        return;
    }

    // Check if ID already exists
    if (findItemIndexById(newItem.id) != -1) {
        printf("[!] Error: An item with ID %d already exists.\n", newItem.id);
        return;
    }

    clearInputBuffer(); // Clear newline left by scanf
    printf("Enter Item Name: ");
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Quantity: ");
    if (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) {
        printf("[!] Invalid quantity.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Price: ");
    if (scanf("%f", &newItem.price) != 1 || newItem.price < 0) {
        printf("[!] Invalid price.\n");
        clearInputBuffer();
        return;
    }

    inventory[itemCount] = newItem;
    itemCount++;
    printf("\n[+] Item added successfully!\n");
}

// Displays all records in a formatted table
void viewInventory() {
    if (itemCount == 0) {
        printf("\n[-] Inventory is empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "Item ID", "Item Name", "Quantity", "Price");
    printf-------------------------------------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-12d $%-9.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

// Modifies quantity or price of an existing item
void updateItem() {
    int id, choice;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    int index = findItemIndexById(id);
    if (index == -1) {
        printf("[-] Item not found.\n");
        return;
    }

    printf("\nUpdating Item: %s\n", inventory[index].name);
    printf("1. Update Quantity\n");
    printf("2. Update Price\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter New Quantity: ");
        scanf("%d", &inventory[index].quantity);
        printf("[+] Quantity updated successfully!\n");
    } else if (choice == 2) {
        printf("Enter New Price: ");
        scanf("%f", &inventory[index].price);
        printf("[+] Price updated successfully!\n");
    } else {
        printf("[!] Invalid choice.\n");
    }
}

// Deletes a record and shifts array elements to maintain continuity
void deleteItem() {
    int id;
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    int index = findItemIndexById(id);
    if (index == -1) {
        printf("[-] Item not found.\n");
        return;
    }

    // Shift elements to the left to overwrite the deleted item
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("[+] Item deleted successfully!\n");
}

// Searches and displays details of a specific item
void searchItem() {
    int id;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);

    int index = findItemIndexById(id);
    if (index == -1) {
        printf("[-] Item not found.\n");
        return;
    }

    printf("\n--- Item Found ---\n");
    printf("ID: %d\n", inventory[index].id);
    printf("Name: %s\n", inventory[index].name);
    printf("Quantity: %d\n", inventory[index].quantity);
    printf("Price: $%.2f\n", inventory[index].price);
}

// Helper function to locate index of an ID
int findItemIndexById(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            return i; // Returns array index
        }
    }
    return -1; // Not found
}

// Helper function to clean input pipeline against trailing characters
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
