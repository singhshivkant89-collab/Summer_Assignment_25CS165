#include <stdio.h>

int main() {
    // Initialize the array
    int numbers[] = {10, 20, 30, 40, 50};
    
    // Calculate total number of elements
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;

    // Loop to accumulate the sum
    for(int i = 0; i < length; i++) {
        sum += numbers[i];
    }

    // Typecast sum to float to get accurate decimal values
    float average = (float)sum / length;

    // Print the results
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
