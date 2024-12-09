// Write a C program to create and display a Circular linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = newNode; // Pointing to itself to make it circular initially
    return newNode;
}

// Function to create a circular linked list
void createCircularList(struct Node** head) {
    int value;
    char choice;

    do {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        
        struct Node* newNode = createNode(value);

        // If the list is empty, the new node is the head node
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* temp = *head;

            // Traverse to the last node
            while (temp->next != *head) {
                temp = temp->next;
            }

            // Link the last node to the new node
            temp->next = newNode;
            newNode->next = *head; // Make the list circular
        }

        printf("Do you want to insert another node? (y/n): ");
        getchar(); // Consume newline character from the buffer
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');
}

// Function to display the circular linked list
void displayCircularList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Continue until we reach the head again
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    createCircularList(&head);
    displayCircularList(head);

    return 0;
}