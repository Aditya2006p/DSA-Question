// Write a C program to implement Linear Search and Binary Search.

#include <stdio.h>

// Function to perform Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to perform Binary Search (Assumes the array is sorted)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }
        // If key is smaller than mid, it must be in the left half
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        // If key is greater than mid, it must be in the right half
        else {
            low = mid + 1;
        }
    }

    return -1; // Return -1 if key is not found
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, key, choice;

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

    // Ask the user for the search method
    printf("Choose the search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted)\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    // Input the element to be searched
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Perform the search based on the user's choice
    int result;
    if (choice == 1) {
        result = linearSearch(arr, n, key);
    } else if (choice == 2) {
        // Sort the array before performing binary search
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        result = binarySearch(arr, n, key);
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    // Display the result of the search
    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}