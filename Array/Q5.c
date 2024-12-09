// Write a C program to find the element with the maximum value from an array.

#include <stdio.h>

int main() {
    int n;

    // Read the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Output the maximum element
    printf("The maximum element in the array is: %d\n", max);

    return 0;
}