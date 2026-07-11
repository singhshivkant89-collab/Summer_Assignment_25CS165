#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the book structure
struct Book {
    int id;
    char title[100];
    char author[100];
    float price;
};

// Function prototypes
void addBook(struct Book library[], int *count);
void displayBooks(const struct Book library[], int count);
void searchBook(const struct Book library[], int count);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by Title");
        printf("\n4. Display Total Book Count");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                printf("\nTotal number of books in the library: %d\n", bookCount);
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add a new book to the library array
void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nError: Library database is full!\n");
        return;
    }

    struct Book newBook;
    newBook.id = *count + 1; // Auto-increment ID based on count

    // Clear any leftover newline character in input stream
    while (getchar() != '\n');

    printf("\nEnter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    printf("Enter Book Price: ");
    while (scanf("%f", &newBook.price) != 1 || newBook.price < 0) {
        printf("Invalid price! Enter a valid positive number: ");
        while (getchar() != '\n'); 
    }

    library[*count] = newBook;
    (*count)++;

    printf("\nSuccess: Book added successfully! assigned Book ID: %d\n", newBook.id);
}

// Function to display all existing books
void displayBooks(const struct Book library[], int count) {
    if (count == 0) {
        printf("\nThe library is empty. No books to display.\n");
        return;
    }

    printf("\n%-6s %-30s %-25s %-10s", "ID", "Title", "Author", "Price");
    printf("\n-------------------------------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("\n%-6d %-30s %-25s $%-9.2f", library[i].id, library[i].title, library[i].author, library[i].price);
    }
    printf("\n-------------------------------------------------------------------------\n");
}

// Function to find a book using case-insensitive partial matchmaking
void searchBook(const struct Book library[], int count) {
    if (count == 0) {
        printf("\nThe library is empty. Cannot search.\n");
        return;
    }

    char searchTitle[100];
    int found = 0;

    while (getchar() != '\n'); // Clear buffer
    printf("\nEnter the Book Title to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    printf("\nSearch Results:");
    printf("\n%-6s %-30s %-25s %-10s", "ID", "Title", "Author", "Price");
    printf("\n-------------------------------------------------------------------------");
    
    for (int i = 0; i < count; i++) {
        // Use strstr for partial match finding
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("\n%-6d %-30s %-25s $%-9.2f", library[i].id, library[i].title, library[i].author, library[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\nNo books found matching the title \"%s\".", searchTitle);
    }
    printf("\n-------------------------------------------------------------------------\n");
}
