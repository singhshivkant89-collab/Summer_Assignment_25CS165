#include <stdio.h>
#include <ctype.h>

// Define a structure to represent a quiz question
typedef struct {
    char questionText[150];
    char options[4][50];
    char correctOption;
} QuizQuestion;

int main() {
    // Initialize the pool of quiz questions
    QuizQuestion quiz[5] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Java", "B. Python", "C. C Language", "D. COBOL"},
            'C'
        },
        {
            "Who is credited with creating the C programming language?",
            {"A. Dennis Ritchie", "B. James Gosling", "C. Bjarne Stroustrup", "D. Guido van Rossum"},
            'A'
        },
        {
            "What is the correct file extension for a standard C source file?",
            {"A. .cpp", "B. .c", "C. .exe", "D. .obj"},
            'B'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. volatile", "C. immutable", "D. const"},
            'D'
        },
        {
            "Which function is used to print output to the console screen in C?",
            {"A. printf()", "B. scanf()", "C. print()", "D. echo()"},
            'A'
        }
    };

    int totalQuestions = 5;
    int score = 0;
    char userChoice;

    printf("=========================================\n");
    printf("     WELCOME TO THE C PROGRAMMING QUIZ   \n");
    printf("=========================================\n\n");

    // Loop through each question sequentially
    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].questionText);
        
        // Print the four multiple-choice options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Input gathering loop with validation
        while (1) {
            printf("Your Answer (A, B, C, or D): ");
            scanf(" %c", &userChoice);
            userChoice = toupper(userChoice); // Handle lowercase inputs gracefully

            if (userChoice >= 'A' && userChoice <= 'D') {
                break; // Valid choice entered, exit inner validation loop
            }
            printf("Invalid selection! Please choose A, B, C, or D.\n");
        }

        // Evaluate the user's answer and give immediate feedback
        if (userChoice == quiz[i].correctOption) {
            printf("\n✅ Correct!\n");
            score++;
        } else {
            printf("\n❌ Incorrect! The right answer was %c.\n", quiz[i].correctOption);
        }
        printf("-----------------------------------------\n\n");
    }

    // Final Performance Summary
    printf("=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, totalQuestions);
    
    // Performance remarks
    if (score == totalQuestions) {
        printf("Remark: Perfect score! You are a C Expert! 🏆\n");
    } else if (score >= totalQuestions / 2) {
        printf("Remark: Good job! Keep practicing. 👍\n");
    } else {
        printf("Remark: Better luck next time! Review your basics. 📚\n");
    }
    printf("=========================================\n");

    return 0;
}
