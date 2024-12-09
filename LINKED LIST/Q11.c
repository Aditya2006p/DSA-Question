// Write a C program to insert a node at the beginning, middle and end of a Circular linked list.

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

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the beginning
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode; // Update the head pointer
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at the middle of the circular linked list
void insertAtMiddle(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (*head == NULL || position == 1) {
        insertAtBeginning(head, value); // Insert at the beginning if the list is empty or position is 1
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    // Traverse to the node just before the specified position
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    // Insert the new node after the found node
    newNode->next = temp->next;
    temp->next = newNode;
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
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Middle\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value to insert at middle: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtMiddle(&head, value, position);
                break;

            case 4:
                displayCircularList(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}