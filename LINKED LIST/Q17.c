// Write a C program to implement Stack Using linked List.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the stack
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

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *top;  // Link the new node to the previous top
    *top = newNode;        // Update the top pointer to the new node
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;  // Return -1 to indicate underflow
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;  // Update the top to the next node
    free(temp);            // Free the memory of the popped node
    return poppedValue;
}

// Function to peek the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;  // Return -1 to indicate the stack is empty
    }
    return top->data;  // Return the data at the top of the stack
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return (top == NULL);  // Return 1 if the stack is empty, otherwise 0
}

// Function to display the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;  // Initially, the stack is empty
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is empty\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            
            case 2:
                value = pop(&top);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            
            case 3:
                value = peek(top);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            
            case 4:
                if (isEmpty(top)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            
            case 5:
                displayStack(top);
                break;
            
            case 6:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}