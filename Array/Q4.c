// Write a C program to store N elements in an array and print the contents of the array in reverse order.

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

    // Print the array elements in reverse order
    printf("The elements in reverse order are:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}