// Write a C program to insert a new node at any given position in a Circular linked list.

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

// Function to insert a new node at any given position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        if (position != 1) {
            printf("Invalid position. The list is empty.\n");
            return;
        }
        *head = newNode;
    } else {
        struct Node* temp = *head;
        int count = 1;

        // If the position is 1, insert at the beginning
        if (position == 1) {
            // Traverse to the last node
            while (temp->next != *head) {
                temp = temp->next;
            }
            // Insert the new node at the beginning
            temp->next = newNode;
            newNode->next = *head;
            *head = newNode;
        } else {
            // Traverse to the node just before the specified position
            while (temp->next != *head && count < position - 1) {
                temp = temp->next;
                count++;
            }

            // If position is greater than the length of the list
            if (temp->next == *head && count < position - 1) {
                printf("Position out of range.\n");
                return;
            }

            // Insert the new node at the specified position
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
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
    int value, position, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Position\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 2:
                displayCircularList(head);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}