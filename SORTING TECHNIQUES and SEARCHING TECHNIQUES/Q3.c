// Write a C program to sort an array using Insertion Sort technique.

#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;
    
    // Start from the second element (index 1) because the first element is already considered sorted
    for (int i = 1; i < n; i++) {
        key = arr[i];  // Element to be inserted
        j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create an array to store the elements
    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using Insertion Sort
    insertionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}