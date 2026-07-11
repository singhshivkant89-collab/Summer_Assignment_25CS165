#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define COURSE_LENGTH 30

// Define a structure to group student metrics together
struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    char course[COURSE_LENGTH];
    float marks;
};

// Function prototypes for readability and structure
void addStudentRecord(struct Student list[], int *count);
void displayAllRecords(const struct Student list[], int count);
void searchStudentRecord(const struct Student list[], int count);

int main() {
    struct Student recordSystem[MAX_STUDENTS];
    int currentStudentCount = 0;
    int userChoice;

    do {
        // Main Interaction Interface
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add a Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &userChoice);

        // Routing user choices to modular logic functions
        switch (userChoice) {
            case 1:
                addStudentRecord(recordSystem, &currentStudentCount);
                break;
            case 2:
                displayAllRecords(recordSystem, currentStudentCount);
                break;
            case 3:
                searchStudentRecord(recordSystem, currentStudentCount);
                break;
            case 4:
                printf("\nExiting system. Have a nice day!\n");
                break;
            default:
                printf("\nInvalid selection! Please enter a number between 1 and 4.\n");
        }
    } while (userChoice != 4);

    return 0;
}

// Function to safely insert a record into our array tracking mechanism
void addStudentRecord(struct Student list[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: System database storage capacity reached!\n");
        return;
    }

    struct Student newStudent;
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    // Clear buffer from preceding numerical standard input 
    getchar(); 

    printf("Enter Full Name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Strip trailing newline

    printf("Enter Course Domain: ");
    fgets(newStudent.course, COURSE_LENGTH, stdin);
    newStudent.course[strcspn(newStudent.course, "\n")] = '\0'; // Strip trailing newline

    printf("Enter Total Accumulated Marks: ");
    scanf("%f", &newStudent.marks);

    // Commit staging data to persistent array index context block
    list[*count] = newStudent;
    (*count)++; // Increment our tracking metric index pointer securely
    
    printf("\nSuccess: Student record added efficiently!\n");
}

// Function to systematically print all stored elements inside the structure array
void displayAllRecords(const struct Student list[], int count) {
    if (count == 0) {
        printf("\nDatabase is currently empty. No records to map.\n");
        return;
    }

    printf("\n---------------------------------------------------------------\n");
    printf("%-10s %-25s %-15s %-10s\n", "Roll No", "Name", "Course", "Marks");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-15s %-10.2f\n", 
               list[i].rollNumber, list[i].name, list[i].course, list[i].marks);
    }
    printf("---------------------------------------------------------------\n");
}

// Function to perform a linear search matching key criteria integers
void searchStudentRecord(const struct Student list[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty. Populate parameters before searching.\n");
        return;
    }

    int targetRoll;
    int recordFoundFlag = 0;

    printf("\nEnter the Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (list[i].rollNumber == targetRoll) {
            printf("\n--- Record Found ---\n");
            printf("Roll Number : %d\n", list[i].rollNumber);
            printf("Full Name   : %s\n", list[i].name);
            printf("Course Track: %s\n", list[i].course);
            printf("Final Marks : %.2f\n", list[i].marks);
            recordFoundFlag = 1;
            break; // Stop evaluating cycles instantly when unique identifier maps
        }
    }

    if (!recordFoundFlag) {
        printf("\nError: Student with Roll Number %d was not found inside storage.\n", targetRoll);
    }
}
