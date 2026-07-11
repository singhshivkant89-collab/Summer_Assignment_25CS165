#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define structure to represent an employee
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

// Global variables to store data
struct Employee empList[MAX_EMPLOYEES];
int totalEmployees = 0;

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
int findIndexById(int id);

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n     EMPLOYEE MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Details");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid option! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new employee record
void addEmployee() {
    if (totalEmployees >= MAX_EMPLOYEES) {
        printf("\nDatabase is full! Cannot add more employees.\n");
        return;
    }

    struct Employee newEmp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &newEmp.id);

    // Check if ID already exists
    if (findIndexById(newEmp.id) != -1) {
        printf("\nError: An employee with ID %d already exists!\n", newEmp.id);
        return;
    }

    printf("Enter Name: ");
    getchar(); // Clear buffer newline character
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = 0; // Strip newline character

    printf("Enter Designation: ");
    fgets(newEmp.designation, sizeof(newEmp.designation), stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &newEmp.salary);

    empList[totalEmployees] = newEmp;
    totalEmployees++;
    printf("\nEmployee added successfully!\n");
}

// Function to display all employee records
void displayEmployees() {
    if (totalEmployees == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < totalEmployees; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", 
               empList[i].id, empList[i].name, empList[i].designation, empList[i].salary);
    }
    printf("-------------------------------------------------------------\n");
}

// Function to search an employee by their ID
void searchEmployee() {
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    int index = findIndexById(id);
    if (index == -1) {
        printf("\nEmployee with ID %d not found.\n", id);
    } else {
        printf("\nRecord Found:");
        printf("\nID: %d", empList[index].id);
        printf("\nName: %s", empList[index].name);
        printf("\nDesignation: %s", empList[index].designation);
        printf("\nSalary: %.2f\n", empList[index].salary);
    }
}

// Function to modify an existing employee's details
void modifyEmployee() {
    int id;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &id);

    int index = findIndexById(id);
    if (index == -1) {
        printf("\nEmployee with ID %d not found.\n", id);
        return;
    }

    printf("\nEnter New Name: ");
    getchar();
    fgets(empList[index].name, sizeof(empList[index].name), stdin);
    empList[index].name[strcspn(empList[index].name, "\n")] = 0;

    printf("Enter New Designation: ");
    fgets(empList[index].designation, sizeof(empList[index].designation), stdin);
    empList[index].designation[strcspn(empList[index].designation, "\n")] = 0;

    printf("Enter New Salary: ");
    scanf("%f", &empList[index].salary);

    printf("\nRecord updated successfully!\n");
}

// Function to delete an employee record
void deleteEmployee() {
    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    int index = findIndexById(id);
    if (index == -1) {
        printf("\nEmployee with ID %d not found.\n", id);
        return;
    }

    // Shift all subsequent elements left to overwrite the deleted item
    for (int i = index; i < totalEmployees - 1; i++) {
        empList[i] = empList[i + 1];
    }
    totalEmployees--;
    printf("\nRecord deleted successfully!\n");
}

// Helper function to find the array index of an employee by ID
int findIndexById(int id) {
    for (int i = 0; i < totalEmployees; i++) {
        if (empList[i].id == id) {
            return i; // Return array index matching the ID
        }
    }
    return -1; // ID not found
}
