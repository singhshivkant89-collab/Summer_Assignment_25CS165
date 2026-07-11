#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define PASS_MARK 40

// Structure to store student information
struct Student {
    int rollNo;
    char name[50];
    int marks[5]; // Marks for Math, Science, English, History, Computer
    int total;
    float percentage;
    char grade[5];
    char result[10];
};

// Function prototypes
void inputStudentData(struct Student s[], int count);
void calculateResults(struct Student s[], int count);
void displayMarksheets(struct Student s[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("=========================================\n");
    printf("    STUDENT MARKSHEET GENERATION SYSTEM  \n");
    printf("=========================================\n");
    
    printf("Enter the number of students (Max %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);
    
    if (numStudents < 1 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Defaulting to 1.\n");
        numStudents = 1;
    }

    // Process system workflow
    inputStudentData(students, numStudents);
    calculateResults(students, numStudents);
    displayMarksheets(students, numStudents);

    return 0;
}

// Function to collect student details and safe-check marks range
void inputStudentData(struct Student s[], int count) {
    const char *subjectNames[] = {"Math", "Science", "English", "History", "Computer"};

    for (int i = 0; i < count; i++) {
        printf("\n--- Entering Details for Student %d ---\n", i + 1);
        
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);
        getchar(); // Clear newline buffer

        printf("Enter Student Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0'; // Remove trailing newline

        for (int j = 0; j < 5; j++) {
            while (1) {
                printf("Enter marks for %s (0-100): ", subjectNames[j]);
                scanf("%d", &s[i].marks[j]);
                
                if (s[i].marks[j] >= 0 && s[i].marks[j] <= 100) {
                    break; // Valid marks input
                }
                printf("Error: Marks must be between 0 and 100.\n");
            }
        }
    }
}

// Function to calculate sum, percents, pass/fail status, and final grade
void calculateResults(struct Student s[], int count) {
    for (int i = 0; i < count; i++) {
        s[i].total = 0;
        int failedSubjectCount = 0;

        // Sum up total and check individual subject passing
        for (int j = 0; j < 5; j++) {
            s[i].total += s[i].marks[j];
            if (s[i].marks[j] < PASS_MARK) {
                failedSubjectCount++;
            }
        }

        s[i].percentage = s[i].total / 5.0;

        // Evaluate overall pass or fail status
        if (failedSubjectCount > 0) {
            strcpy(s[i].result, "FAIL");
            strcpy(s[i].grade, "F");
        } else {
            strcpy(s[i].result, "PASS");
            
            // Assign grades based on criteria thresholds
            if (s[i].percentage >= 90) strcpy(s[i].grade, "A+");
            else if (s[i].percentage >= 80) strcpy(s[i].grade, "A");
            else if (s[i].percentage >= 70) strcpy(s[i].grade, "B");
            else if (s[i].percentage >= 60) strcpy(s[i].grade, "C");
            else if (s[i].percentage >= 50) strcpy(s[i].grade, "D");
            else strcpy(s[i].grade, "E");
        }
    }
}

// Function to print highly-scannable report cards
void displayMarksheets(struct Student s[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\n\n=================================================");
        printf("\n               OFFICIAL MARKSHEET                ");
        printf("\n=================================================");
        printf("\n Roll No: %-10d Name: %-25s", s[i].rollNo, s[i].name);
        printf("\n-------------------------------------------------");
        printf("\n SUBJECT          MAX MARKS      OBTAINED MARKS  ");
        printf("\n-------------------------------------------------");
        printf("\n Math             100            %d", s[i].marks[0]);
        printf("\n Science          100            %d", s[i].marks[1]);
        printf("\n English          100            %d", s[i].marks[2]);
        printf("\n History          100            %d", s[i].marks[3]);
        printf("\n Computer         100            %d", s[i].marks[4]);
        printf("\n-------------------------------------------------");
        printf("\n GRAND TOTAL:     500 / %-3d", s[i].total);
        printf("\n PERCENTAGE:      %.2f%%", s[i].percentage);
        printf("\n FINAL GRADE:     %-5s Status: %-10s", s[i].grade, s[i].result);
        printf("\n=================================================\n");
    }
}
