// Write a C program to create and display a Singly Linked List.

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node
struct Node {
    int data;           // Store data
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;   // Set the data of the new node
    newNode->next = NULL;     // Set the next pointer to NULL
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;  // Temporary pointer to traverse the list
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print the data of each node
        temp = temp->next;          // Move to the next node
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the list as NULL
    struct Node* temp;
    int n, value;

    // Input: number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create and display the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        
        // Create a new node and insert it at the end of the list
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;  // If the list is empty, make the new node the head
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = newNode;  // Link the last node to the new node
        }
    }

    // Display the linked list
    displayList(head);

    return 0;
}