#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void removeDuplicates(Node* head) {
    Node *temp = head, *prev, *temp1;

    while (temp != NULL && temp->next != NULL) {
        prev = temp;
        while (prev->next != NULL) {
            if (temp->data == prev->next->data) {
                // Duplicate found, remove it
                temp1 = prev->next;
                prev->next = prev->next->next;
                free(temp1);
            } else {
                prev = prev->next;
            }
        }
        temp = temp->next;
    }
}

// Helper functions to create and print the linked list
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(20);

    printf("Original list:\n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
