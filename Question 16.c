#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int digits = 0;
    double sum = 0.0;

    // Count the total number of digits
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    // Reset temp to the original number
    temp = num;

    // Calculate the sum of power of individual digits
    while (temp != 0) {
        int remainder = temp % 10;
        
        // Use round() to avoid floating-point inaccuracies with pow()
        sum += round(pow(remainder, digits)); 
        temp /= 10;
    }

    // Check if the sum matches the original number
    if ((int)sum == originalNum) {
        return 1; // It is an Armstrong number
    } else {
        return 0; // It is not
    }
}

int main() {
    int start, end;

    // Get range limits from the user
    printf("Enter the starting number of the range: ");
    if (scanf("%d", &start) != 1) return 1;

    printf("Enter the ending number of the range: ");
    if (scanf("%d", &end) != 1) return 1;

    // Swap the numbers if the starting limit is greater than the ending limit
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    
    // Iterate through the range and verify each number
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}