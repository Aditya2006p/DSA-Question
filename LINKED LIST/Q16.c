// Write a C program to create and reorder a linked list placing all even- numbered nodes ahead of all odd-numbered nodes.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reorder the linked list placing even-numbered nodes first
void reorderList(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node *evenHead = NULL, *oddHead = NULL;
    struct Node *evenTail = NULL, *oddTail = NULL;
    struct Node *current = *head;

    // Split the list into two parts: even and odd nodes
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = current;
                evenTail = evenHead;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = current;
                oddTail = oddHead;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    // Connect the even list with the odd list
    if (evenTail != NULL) {
        evenTail->next = oddHead;
    }

    // Ensure the last node points to NULL
    if (oddTail != NULL) {
        oddTail->next = NULL;
    }

    // Update the head of the list to point to the evenHead
    *head = evenHead;
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Reorder the linked list (Even nodes first)\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 2:
                reorderList(&head);
                printf("List reordered: Even nodes first.\n");
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}