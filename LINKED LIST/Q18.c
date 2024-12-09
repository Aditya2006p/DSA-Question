// Write a C program to implement queue using double pointers.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
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

// Function to enqueue an element into the queue
void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    if (*rear == NULL) {
        *front = *rear = newNode;  // If the queue is empty, both front and rear point to the new node
    } else {
        (*rear)->next = newNode;   // Add the new node at the end of the queue
        *rear = newNode;           // Update the rear pointer
    }
    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element from the queue
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return -1;  // Return -1 to indicate underflow
    }
    struct Node* temp = *front;
    int dequeuedValue = temp->data;
    *front = (*front)->next;  // Update the front pointer to the next node
    if (*front == NULL) {
        *rear = NULL;  // If the queue becomes empty, set rear to NULL as well
    }
    free(temp);  // Free the memory of the dequeued node
    return dequeuedValue;
}

// Function to peek the front element of the queue
int peek(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;  // Return -1 to indicate the queue is empty
    }
    return front->data;  // Return the data at the front of the queue
}

// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return (front == NULL);  // Return 1 if the queue is empty, otherwise 0
}

// Function to display the queue
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;  // Initially, the queue is empty
    struct Node* rear = NULL;   // Initially, the rear is NULL
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if queue is empty\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            
            case 2:
                value = dequeue(&front, &rear);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            
            case 3:
                value = peek(front);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            
            case 4:
                if (isEmpty(front)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            
            case 5:
                displayQueue(front);
                break;
            
            case 6:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}