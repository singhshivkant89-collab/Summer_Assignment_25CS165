#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the structure for storing book information
struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued; // 0 = Available, 1 = Issued
};

// Global variables
struct Book library[MAX_BOOKS];
int book_count = 0;

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n   MINI LIBRARY MANAGEMENT SYSTEM ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Remove trailing newline character left by scanf

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nThank you for using the Library System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    
    printf("\nEnter Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID format. Operation canceled.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Check if Book ID already exists
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == newBook.id) {
            printf("Error: A book with ID %d already exists.\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    newBook.is_issued = 0; // New books are available by default

    library[book_count] = newBook;
    book_count++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (book_count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < book_count; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n--------------------------------------------------------------------------------\n");
}

// Function to search for a book by Title
void searchBook() {
    if (book_count == 0) {
        printf("\nThe library is completely empty.\n");
        return;
    }

    char search_title[100];
    int found = 0;

    printf("\nEnter the Title of the book to search: ");
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = '\0';

    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) { // Case-insensitive matching
            if (!found) {
                printf("\nBook(s) Found:\n");
                printf("%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
                printf("\n--------------------------------------------------------------------------------");
            }
            printf("\n%-10d %-30s %-25s %-15s", 
                   library[i].id, 
                   library[i].title, 
                   library[i].author, 
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
        }
    }
    
    if (found) {
        printf("\n--------------------------------------------------------------------------------\n");
    } else {
        printf("\nNo book found matching the title: \"%s\"\n", search_title);
    }
}

// Function to issue a book
void issueBook() {
    int search_id;
    printf("\nEnter Book ID to Issue: ");
    if (scanf("%d", &search_id) != 1) {
        printf("Invalid entry.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            if (library[i].is_issued == 1) {
                printf("\nSorry, the book \"%s\" is already issued.\n", library[i].title);
            } else {
                library[i].is_issued = 1;
                printf("\nBook \"%s\" has been issued successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", search_id);
}

// Function to return a book
void returnBook() {
    int search_id;
    printf("\nEnter Book ID to Return: ");
    if (scanf("%d", &search_id) != 1) {
        printf("Invalid entry.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            if (library[i].is_issued == 0) {
                printf("\nThis book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nBook \"%s\" returned successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", search_id);
}

// Helper function to handle input stream clean-up
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
