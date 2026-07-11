#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "payroll.txt"

// Structure to store employee and salary information
struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund Deduction
    float gross_salary;
    float net_salary;
};

// Function prototypes
void addEmployee();
void displayAllEmployees();
void searchEmployee();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee & Compute Salary");
        printf("\n2. Display All Employee Payrolls");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to calculate allowances, gross, and net salaries
void calculateSalary(struct Employee *emp) {
    // Formula Breakdown:
    // HRA = 30% of Basic, DA = 20% of Basic, PF = 12% of Basic
    emp->hra = emp->basic_salary * 0.30;
    emp->da = emp->basic_salary * 0.20;
    emp->pf = emp->basic_salary * 0.12;
    
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    emp->net_salary = emp->gross_salary - emp->pf;
}

// Function to add a record and write it to a text file
void addEmployee() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("\nError opening file for storage!\n");
        return;
    }

    struct Employee emp;

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear buffer newline characters

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Strip newline from string

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0; 

    printf("Enter Basic Monthly Salary: ");
    scanf("%f", &emp.basic_salary);

    // Compute automatic financial fields
    calculateSalary(&emp);

    // Append standard struct properties to raw data file 
    fprintf(file, "%d;%s;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f\n", 
            emp.id, emp.name, emp.designation, emp.basic_salary, 
            emp.hra, emp.da, emp.pf, emp.gross_salary, emp.net_salary);

    fclose(file);
    printf("\nEmployee added and payroll computed successfully!\n");
}

// Function to read and list all stored records
void displayAllEmployees() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo payroll records found. Add an employee first!\n");
        return;
    }

    struct Employee emp;
    char line[256];

    printf("\n========================================================================================================\n");
    printf("%-5s %-20s %-15s %-12s %-10s %-10s %-10s %-12s\n", 
           "ID", "Name", "Designation", "Basic", "HRA", "DA", "PF Deduct", "Net Pay");
    printf("========================================================================================================\n");

    while (fgets(line, sizeof(line), file)) {
        // Parse semi-colon delimited file fields
        sscanf(line, "%d;[^;];[^;];%f;%f;%f;%f;%f;%f", 
               &emp.id, emp.name, emp.designation, &emp.basic_salary, 
               &emp.hra, &emp.da, &emp.pf, &emp.gross_salary, &emp.net_salary);
        
        // Re-read strings with precision matching manually split tokens safely
        char *token = strtok(line, ";");
        emp.id = atoi(token);
        strcpy(emp.name, strtok(NULL, ";"));
        strcpy(emp.designation, strtok(NULL, ";"));
        emp.basic_salary = atof(strtok(NULL, ";"));
        emp.hra = atof(strtok(NULL, ";"));
        emp.da = atof(strtok(NULL, ";"));
        emp.pf = atof(strtok(NULL, ";"));
        emp.gross_salary = atof(strtok(NULL, ";"));
        emp.net_salary = atof(strtok(NULL, ";"));

        printf("%-5d %-20s %-15s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f\n", 
               emp.id, emp.name, emp.designation, emp.basic_salary, 
               emp.hra, emp.da, emp.pf, emp.net_salary);
    }
    printf("========================================================================================================\n");
    fclose(file);
}

// Function to locate an employee record by specific ID key
void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo payroll records found!\n");
        return;
    }

    int searchId, found = 0;
    char line[256];
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fgets(line, sizeof(line), file)) {
        char tempLine[256];
        strcpy(tempLine, line); // Duplicate line because strtok modifies it

        char *token = strtok(tempLine, ";");
        if (atoi(token) == searchId) {
            found = 1;
            
            // Extract remaining attributes
            strcpy(emp.name, strtok(NULL, ";"));
            strcpy(emp.designation, strtok(NULL, ";"));
            emp.basic_salary = atof(strtok(NULL, ";"));
            emp.hra = atof(strtok(NULL, ";"));
            emp.da = atof(strtok(NULL, ";"));
            emp.pf = atof(strtok(NULL, ";"));
            emp.gross_salary = atof(strtok(NULL, ";"));
            emp.net_salary = atof(strtok(NULL, ";"));

            printf("\n--- Employee Payroll Found ---");
            printf("\nID:          %d", searchId);
            printf("\nName:        %s", emp.name);
            printf("\nPosition:    %s", emp.designation);
            printf("\nBasic Pay:   $%.2f", emp.basic_salary);
            printf("\nHRA (+):     $%.2f", emp.hra);
            printf("\nDA (+):      $%.2f", emp.da);
            printf("\nPF (-):      $%.2f", emp.pf);
            printf("\n-----------------------------");
            printf("\nGross Pay:   $%.2f", emp.gross_salary);
            printf("\nNet TakeHome:$%.2f\n", emp.net_salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(file);
}
