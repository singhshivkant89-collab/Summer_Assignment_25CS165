#include <stdio.h>

int main() {
    int age;

    // Prompt the user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check voting eligibility
    if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } else {
        printf("Sorry, you are not eligible to vote yet.\n");
    }

    return 0;
}
