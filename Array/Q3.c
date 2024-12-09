// Write a C program to determine the intersection of two given arrays.

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

    // Intersection of the two arrays
    int intersectionArray[n1 < n2 ? n1 : n2]; // To store the intersection elements
    int intersectionSize = 0;

    // Check for common elements
    for (int i = 0; i < n1; i++) {
        if (isPresent(arr2, n2, arr1[i]) && !isPresent(intersectionArray, intersectionSize, arr1[i])) {
            intersectionArray[intersectionSize++] = arr1[i];
        }
    }

    // Output the intersection of the two arrays
    if (intersectionSize > 0) {
        printf("Intersection of the two arrays is:\n");
        for (int i = 0; i < intersectionSize; i++) {
            printf("%d ", intersectionArray[i]);
        }
        printf("\n");
    } else {
        printf("There is no intersection between the two arrays.\n");
    }

    return 0;
}