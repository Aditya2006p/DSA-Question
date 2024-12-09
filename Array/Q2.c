// Write a C program to determine the union of two given arrays.

#include <stdio.h>

int isPresent(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return 1; // Element is present in the array
        }
    }
    return 0; // Element is not present in the array
}

int main() {
    int n1, n2;

    // Read the size of the first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];

    // Read elements of the first array
    printf("Enter elements of the first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Read the size of the second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];

    // Read elements of the second array
    printf("Enter elements of the second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Union of the two arrays
    int unionArray[n1 + n2];
    int unionSize = 0;

    // Add elements of the first array to the union
    for (int i = 0; i < n1; i++) {
        unionArray[unionSize++] = arr1[i];
    }

    // Add elements of the second array to the union if not already present
    for (int i = 0; i < n2; i++) {
        if (!isPresent(arr1, n1, arr2[i])) {
            unionArray[unionSize++] = arr2[i];
        }
    }

    // Output the union of the two arrays
    printf("Union of the two arrays is:\n");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArray[i]);
    }
    printf("\n");

    return 0;
}