#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100 // Maximum elements the array can hold

// Function prototypes for modularity
void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(const int arr[], int size);

int main() {
    int arr[MAX_CAPACITY];
    int size = 0; // Tracks the current number of elements in the array
    int choice;

    do {
        // Displaying the system menu
        printf("\n=================================");
        printf("\n   ARRAY OPERATIONS SYSTEM MENU   ");
        printf("\n=================================");
        printf("\n 1. Create / Initialize Array");
        printf("\n 2. Display Array Elements");
        printf("\n 3. Insert an Element");
        printf("\n 4. Delete an Element");
        printf("\n 5. Search for an Element");
        printf("\n 6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        // Input validation for the menu choice
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                printf("\nExiting the system. Thank you!\n");
                break;
            default:
                printf("\n[Error] Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Create or overwrite the array structure
void createArray(int arr[], int *size) {
    int n;
    printf("\nEnter the number of elements to initialize (Max %d): ", MAX_CAPACITY);
    scanf("%d", &n);

    if (n < 0 || n > MAX_CAPACITY) {
        printf("[Error] Initialization failed. Invalid size.\n");
        return;
    }

    *size = n;
    if (n > 0) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < *size; i++) {
            printf("Element [%d]: ", i + 1); // 1-based indexing for user visibility
            scanf("%d", &arr[i]);
        }
        printf("[Success] Array initialized successfully.\n");
    } else {
        printf("[Info] Array initialized as empty.\n");
    }
}

// 2. Traverse and print all elements
void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\n[Info] The array is currently empty.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n");
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("Total Active Elements: %d\n", size);
}

// 3. Insert an element at a specified position
void insertElement(int arr[], int *size) {
    if (*size >= MAX_CAPACITY) {
        printf("\n[Error] Overflow! Array capacity reached.\n");
        return;
    }

    int element, position;
    printf("\nEnter the element value to insert: ");
    scanf("%d", &element);
    printf("Enter target position (1 to %d): ", *size + 1);
    scanf("%d", &position);

    // Validation: Elements must remain contiguous
    if (position < 1 || position > *size + 1) {
        printf("[Error] Invalid position. Out of bounds.\n");
        return;
    }

    // Shift elements right to open up a slot
    for (int i = *size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = element; // Map 1-based user index to 0-based memory index
    (*size)++;                   // Increment the dynamic size tracker
    printf("[Success] Element inserted safely.\n");
}

// 4. Delete an element from a specified position
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\n[Error] Underflow! Nothing to delete from an empty array.\n");
        return;
    }

    int position;
    printf("\nEnter target deletion position (1 to %d): ", *size);
    scanf("%d", &position);

    if (position < 1 || position > *size) {
        printf("[Error] Invalid position. Out of bounds.\n");
        return;
    }

    int deletedValue = arr[position - 1];

    // Shift elements left to overwrite the target spot
    for (int i = position - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrement dynamic size tracker
    printf("[Success] Element %d removed from position %d.\n", deletedValue, position);
}

// 5. Linear search to find element placement
void searchElement(const int arr[], int size) {
    if (size == 0) {
        printf("\n[Info] Array is empty. Element not found.\n");
        return;
    }

    int target, found = 0;
    printf("\nEnter the element value to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("[Found] Element %d exists at position %d (Index %d).\n", target, i + 1, i);
            found = 1;
        }
    }

    if (!found) {
        printf("[Not Found] Element %d does not exist in the array.\n", target);
    }
}
