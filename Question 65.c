#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int size1, size2, sizeMerged;
    int i, j;

    // Input elements for the first array
    printf("Enter the number of elements for the first array: ");
    scanf("%d", &size1);
    printf("Enter %d elements:\n", size1);
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input elements for the second array
    printf("\nEnter the number of elements for the second array: ");
    scanf("%d", &size2);
    printf("Enter %d elements:\n", size2);
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Copy elements of the first array into the merged array
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    // Copy elements of the second array into the merged array
    sizeMerged = size1 + size2;
    for (i = 0, j = size1; j < sizeMerged; i++, j++) {
        merged[j] = arr2[i];
    }

    // Display the final merged array
    printf("\nThe merged array is:\n");
    for (i = 0; i < sizeMerged; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
