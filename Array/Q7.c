// Write a C program to Implementation Stack Using Array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Define the stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Initialize the top to -1, indicating an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;  // If top reaches MAX-1, the stack is full
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;  // If top is -1, the stack is empty
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;  // Increment top and add the element
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! No elements to pop\n");
        return -1;  // Return -1 if the stack is empty
    }
    int poppedValue = stack->arr[stack->top--];  // Return top element and decrement top
    return poppedValue;
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No element to peek\n");
        return -1;  // Return -1 if the stack is empty
    }
    return stack->arr[stack->top];  // Return the top element without removing it
}

// Function to display the stack elements
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Nothing to display\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    // Perform stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);  // This should give a Stack Overflow error

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));  // Pop an element
    display(&stack);

    printf("Top element is: %d\n", peek(&stack));  // Peek the top element

    return 0;
}