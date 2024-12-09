// Write a C program to Implemeritation queue Using Array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

// Define the queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = -1;  // Initialize the front to -1, indicating an empty queue
    queue->rear = -1;   // Initialize the rear to -1, indicating an empty queue
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX - 1);  // If rear reaches MAX-1, the queue is full
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);  // If front is -1, the queue is empty
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;  // If the queue is empty, set front to 0
    }
    queue->arr[++queue->rear] = value;  // Increment rear and insert the element
    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! No elements to dequeue\n");
        return -1;  // Return -1 if the queue is empty
    }
    int dequeuedValue = queue->arr[queue->front];  // Get the front element
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;  // If the queue becomes empty, reset both front and rear
    } else {
        queue->front++;  // Increment front to dequeue the next element
    }
    return dequeuedValue;
}

// Function to peek the front element of the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No element to peek\n");
        return -1;  // Return -1 if the queue is empty
    }
    return queue->arr[queue->front];  // Return the front element without removing it
}

// Function to display the queue elements
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Nothing to display\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    // Perform queue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);  // This should give a Queue Overflow error

    display(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));  // Dequeue an element
    display(&queue);

    printf("Front element is: %d\n", peek(&queue));  // Peek the front element

    return 0;
}