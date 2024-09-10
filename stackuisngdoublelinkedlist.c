#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Stack structure using a doubly linked list
struct stack {
    struct Node* top;
};

// Function to check if the stack is empty
int isempty(struct stack* ptr) {
    return (ptr->top == NULL);
}

// Function to push a value onto the stack
void push(struct stack* ptr, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = ptr->top; // Previous pointer points to the current top

    if (ptr->top != NULL) {
        ptr->top->next = newNode; // Set the next of the current top to the new node
    }
    
    ptr->top = newNode; // Update the top pointer to the new node
}

// Function to pop a value from the stack
int pop(struct stack* ptr) {
    if (isempty(ptr)) {
        printf("Underflow\n");
        return -1; // Return an error value
    } else {
        struct Node* temp = ptr->top;
        int val = temp->data;
        ptr->top = temp->prev; // Update the top to the previous node

        if (ptr->top != NULL) {
            ptr->top->next = NULL; // Remove the reference to the popped node
        }

        free(temp);
        return val;
    }
}

// Function to check if the stack is full (not applicable in doubly linked list implementation)
int isfull(struct stack* ptr) {
    return 0; // Since it's a linked list, it can grow dynamically
}

// Main function to test the stack implementation
int main() {
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = NULL; // Initialize the stack

    printf("Before pushing, full: %d\n", isfull(sp));
    printf("Before pushing, empty: %d\n", isempty(sp));
    
    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);

    printf("After pushing, full: %d\n", isfull(sp));
    printf("After pushing, empty: %d\n", isempty(sp));

    printf("Popped value: %d\n", pop(sp));
    printf("Popped value: %d\n", pop(sp));

    return 0;
}
