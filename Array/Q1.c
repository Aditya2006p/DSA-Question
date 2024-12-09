// Write a C program to calculate the sum of all even elements in an array.

#include <stdio.h>

int main() {
    int n, sum = 0;

    // Read the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of even elements
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    // Output the result
    printf("The sum of all even elements in the array is: %d\n", sum);

    return 0;
}