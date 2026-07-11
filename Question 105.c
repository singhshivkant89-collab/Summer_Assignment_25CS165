#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the structure to hold student details
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Global array and counter to manage records
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function Prototypes
void displayMenu();
void addStudent();
void displayAllStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to print the main menu
void displayMenu() {
    printf("\n1. Add | 2. Display | 3. Search | 4. Update | 5. Delete | 6. Exit\n");
}

// Function to add a unique student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) { printf("\nSystem full!\n"); return; }
    printf("\nEnter ID: "); scanf("%d", &students[studentCount].id);
    printf("Enter Name: "); while (getchar() != '\n');
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;
    printf("Enter Age: "); scanf("%d", &students[studentCount].age);
    printf("Enter GPA: "); scanf("%f", &students[studentCount].gpa);
    studentCount++;
}

// Function to display all records
void displayAllStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to find a student
void searchStudent() {
    int id; printf("\nEnter ID to search: "); scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Found: %s, GPA: %.2f\n", students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Not found.\n");
}

// Function to modify existing data
void updateStudent() {
    int id; printf("\nEnter ID to update: "); scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter New Name: "); while (getchar() != '\n');
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            printf("Enter New GPA: "); scanf("%f", &students[i].gpa);
            return;
        }
    }
    printf("Not found.\n");
}

// Function to remove a record
void deleteStudent() {
    int id, found = 0; printf("\nEnter ID to delete: "); scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) students[j] = students[j + 1];
            studentCount--; found = 1; break;
        }
    }
    if (found) printf("Deleted.\n"); else printf("Not found.\n");
}
