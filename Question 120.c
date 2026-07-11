#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

// Function Prototypes
int addStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rollNumbers[], int count);
void displayStudents(const char names[MAX_STUDENTS][NAME_LENGTH], const int rollNumbers[], int count);
void searchStudent(const char names[MAX_STUDENTS][NAME_LENGTH], const int rollNumbers[], int count);

int main() {
    // 2D Array to store multiple string names
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    // 1D Array to store roll numbers
    int rollNumbers[MAX_STUDENTS];
    int studentCount = 0;
    int choice = 0;

    while (choice != 4) {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                studentCount = addStudent(studentNames, rollNumbers, studentCount);
                break;
            case 2:
                displayStudents(studentNames, rollNumbers, studentCount);
                break;
            case 3:
                searchStudent(studentNames, rollNumbers, studentCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

// Function to add a new student
int addStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rollNumbers[], int count) {
    if (count >= MAX_STUDENTS) {
        printf("Error: Student database is full.\n");
        return count;
    }

    printf("\nEnter Student Name: ");
    // Clear the input buffer
    getchar(); 
    // Read a string including spaces
    fgets(names[count], NAME_LENGTH, stdin);
    
    // Remove the trailing newline character added by fgets
    names[count][strcspn(names[count], "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &rollNumbers[count]);

    printf("Student added successfully!\n");
    return count + 1;
}

// Function to display all students
void displayStudents(const char names[MAX_STUDENTS][NAME_LENGTH], const int rollNumbers[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %s | Roll No: %d\n", i + 1, names[i], rollNumbers[i]);
    }
}

// Function to search for a student by name
void searchStudent(const char names[MAX_STUDENTS][NAME_LENGTH], const int rollNumbers[], int count) {
    if (count == 0) {
        printf("\nNo student records found to search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    printf("\nEnter name to search: ");
    getchar(); 
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        // String comparison to check if names match
        if (strcmp(names[i], searchName) == 0) {
            printf("\nStudent found! Name: %s, Roll No: %d\n", names[i], rollNumbers[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with name '%s' not found.\n", searchName);
    }
}
