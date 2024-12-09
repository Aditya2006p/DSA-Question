// Write a C program to insert string in linked list in alphabetical order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
struct Node {
    char data[100]; // To store the string
    struct Node* next;
};

// Function to create a new node with a given string
struct Node* createNode(char* str) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a string in alphabetical order in the linked list
void insertInOrder(struct Node** head, char* str) {
    struct Node* newNode = createNode(str);
    struct Node* current;
    
    // If the list is empty or the new string should be inserted at the beginning
    if (*head == NULL || strcmp((*head)->data, str) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse the list to find the correct position
        current = *head;
        while (current->next != NULL && strcmp(current->next->data, str) < 0) {
            current = current->next;
        }
        // Insert the new node after current
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    char str[100];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert string in alphabetical order\n");
        printf("2. Display linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter the string to insert: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';  // Remove the newline character from the input
                insertInOrder(&head, str);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}