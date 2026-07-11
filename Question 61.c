#include <stdio.h>

// Method 1: Using Math Summation Formula
// Time Complexity: O(n), Space Complexity: O(1)
int findMissingBySum(int arr[], int size) {
    // Total elements should be size + 1 (including the missing one)
    int n = size + 1; 
    
    // Formula for sum of first n natural numbers: n * (n + 1) / 2
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;
    
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    
    return expectedSum - actualSum;
}

// Method 2: Using Bitwise XOR (Prevents integer overflow for large arrays)
// Time Complexity: O(n), Space Complexity: O(1)
int findMissingByXOR(int arr[], int size) {
    int xorTotal = 0;
    int xorArray = 0;
    
    // XOR all numbers from 1 to N (size + 1)
    for (int i = 1; i <= size + 1; i++) {
        xorTotal ^= i;
    }
    
    // XOR all elements present in the array
    for (int i = 0; i < size; i++) {
        xorArray ^= arr[i];
    }
    
    // The identical elements cancel each other out, leaving the missing number
    return xorTotal ^ xorArray;
}

int main() {
    // Array missing the number 4 (Numbers 1 to 6 should be present)
    int arr[] = {1, 2, 6, 3, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("--- Input Array ---\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Calculate using both approaches
    int missingSum = findMissingBySum(arr, size);
    int missingXOR = findMissingByXOR(arr, size);
    
    printf("Missing Number (Sum Method): %d\n", missingSum);
    printf("Missing Number (XOR Method): %d\n", missingXOR);
    
    return 0;
}
