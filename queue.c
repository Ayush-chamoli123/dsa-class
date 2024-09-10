#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int size;
    int r; // rear
    int f; // front
    int *arr; // dynamic array to store elements of the queue
};

// Function to check if the queue is empty
int isempty(struct queue *q) {
    return (q->r == q->f);
}

// Function to check if the queue is full
int isfull(struct queue* q) {
    return (q->r == q->size - 1);
}

// Function to add an element to the queue
void enqueue(struct queue **q, int val) {
    if (isfull(*q)) {
        printf("This queue is full\n");
    } else {
        (*q)->r++;
        (*q)->arr[(*q)->r] = val; // Add the value to the queue
        printf("Enqueued %d to the queue\n", val);
    }
}


// Function to initialize the queue
void initializeQueue(struct queue **q, int size) {
    // Allocate memory for the queue structure
    *q = (struct queue*)malloc(sizeof(struct queue));
    if (*q == NULL) {
        printf("Memory allocation failed for the queue structure!\n");
        exit(1); // Exit if memory allocation fails
    }

    (*q)->size = size; // Set the size of the queue
    (*q)->f = (*q)->r = -1; // Initialize front and rear to -1

    // Allocate memory for the queue's dynamic array
    (*q)->arr = (int*)malloc((*q)->size * sizeof(int));
    if ((*q)->arr == NULL) {
        printf("Memory allocation failed for the queue array!\n");
        free(*q); // Free the memory allocated for the queue structure
        exit(1); // Exit if memory allocation fails
    }
}

int main() {
    struct queue *q; // Declare a queue pointer

    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size); // Read the size of the queue

    initializeQueue(&q, size); // Initialize the queue with the given size

    // Enqueue some elements
    enqueue(&q, 12);
    enqueue(&q, 11);

    // Additional operations can be added here (e.g., dequeue, display, etc.)

    free(q->arr); // Free the allocated memory for the array
    free(q); // Free the allocated memory for the queue structure

    return 0;
}

