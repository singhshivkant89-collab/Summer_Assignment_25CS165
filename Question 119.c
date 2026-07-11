#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee(Employee emp[], int *count);
void displayEmployees(const Employee emp[], int count);
void searchEmployee(const Employee emp[], int count);
void updateEmployee(Employee emp[], int count);
void deleteEmployee(Employee emp[], int *count);

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\n====================================");
        printf("\n   MINI EMPLOYEE MANAGEMENT SYSTEM  ");
        printf("\n====================================");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Update Employee Details");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;
            case 2:
                displayEmployees(employees, employeeCount);
                break;
            case 3:
                searchEmployee(employees, employeeCount);
                break;
            case 4:
                updateEmployee(employees, employeeCount);
                break;
            case 5:
                deleteEmployee(employees, &employeeCount);
                break;
            case 6:
                printf("\nExiting the system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Function to Add a New Employee
void addEmployee(Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: System database is full!\n");
        return;
    }

    Employee newEmp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &newEmp.id);
    
    // Check if ID already exists
    for (int i = 0; i < *count; i++) {
        if (emp[i].id == newEmp.id) {
            printf("Error: Employee ID %d already exists!\n", newEmp.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); // Clear trailing newline from previous scanf
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(newEmp.designation, sizeof(newEmp.designation), stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &newEmp.salary);

    emp[*count] = newEmp;
    (*count)++;
    printf("\nEmployee record added successfully!\n");
}

// 2. Function to Display All Records
void displayEmployees(const Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n--------------------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("\n%-10d %-20s %-20s %-10.2f", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    }
    printf("\n");
}

// 3. Function to Search for an Employee
void searchEmployee(const Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchId) {
            printf("\nEmployee Found:");
            printf("\nID: %d", emp[i].id);
            printf("\nName: %s", emp[i].name);
            printf("\nDesignation: %s", emp[i].designation);
            printf("\nSalary: $%.2f\n", emp[i].salary);
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", searchId);
}

// 4. Function to Update an Employee's Data
void updateEmployee(Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int updateId;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == updateId) {
            printf("\nCurrent Details - Name: %s, Position: %s, Salary: $%.2f", emp[i].name, emp[i].designation, emp[i].salary);
            
            printf("\nEnter New Name: ");
            getchar();
            fgets(emp[i].name, sizeof(emp[i].name), stdin);
            emp[i].name[strcspn(emp[i].name, "\n")] = '\0';

            printf("Enter New Designation: ");
            fgets(emp[i].designation, sizeof(emp[i].designation), stdin);
            emp[i].designation[strcspn(emp[i].designation, "\n")] = '\0';

            printf("Enter New Salary: ");
            scanf("%f", &emp[i].salary);

            printf("\nEmployee record updated successfully!\n");
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", updateId);
}

// 5. Function to Delete an Employee Record
void deleteEmployee(Employee emp[], int *count) {
    if (*count == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < *count; i++) {
        if (emp[i].id == deleteId) {
            // Shift remaining records to fill the blank spot
            for (int j = i; j < *count - 1; j++) {
                emp[j] = emp[j + 1];
            }
            (*count)--;
            printf("\nEmployee record deleted successfully!\n");
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", deleteId);
}
