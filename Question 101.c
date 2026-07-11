#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;

    // Seed the random number generator using the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("=========================================\n");
    printf("   Welcome to the Number Guessing Game!  \n");
    printf("=========================================\n");
    printf("I have selected a secret number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // Loop until the player guesses the correct number
    do {
        printf("Enter your guess: ");
        
        // Handle invalid character inputs safely
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a valid number.\n\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        attempts++; // Increment attempt counter

        // Provide feedback on the guess
        if (guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } else {
            printf("\n🎉 Congratulations! You guessed it right!\n");
            printf("The secret number was %d.\n", secret_number);
            printf("It took you %d attempts to win.\n", attempts);
        }

    } while (guess != secret_number);

    return 0;
}
