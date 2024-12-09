// Write a C program to evaluate any postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For checking if character is a digit

#define MAX 50  // Maximum size of the stack

// Define the stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initStack(&stack);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        // If the current character is a digit, push it onto the stack
        if (isdigit(current)) {
            push(&stack, current - '0');  // Convert char to integer
        }
        // If the current character is an operator
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            int operand2 = pop(&stack);  // Pop two operands
            int operand1 = pop(&stack);

            int result;
            // Perform the operation and push the result back onto the stack
            switch (current) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&stack, result);
        }
    }

    // The final result is the only element left in the stack
    return pop(&stack);
}

int main() {
    char postfix[MAX];

    // Read the postfix expression
    printf("Enter a postfix expression: ");
    fgets(postfix, MAX, stdin);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);

    // Print the result
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}