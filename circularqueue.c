#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int size;
    int r; // rear
    int f; // front
    int *arr; 
};

// Function to check if the queue is empty
int isempty(struct queue *q) {
    return (q->r == q->f);
}

// Function to check if the queue is full
int isfull(struct queue* q) {
    return ((q->r + 1) % q->size == q->f);
}

// Function to add an element to the queue
void enqueue(struct queue *q, int val) {
    if (isfull(q)) {
        printf("This queue is full\n");
    } else {
        q->r = (q->r + 1) % q->size; // Increment rear in a circular fashion
        q->arr[q->r] = val; // Add the value to the queue
        printf("Enqueued %d to the queue\n", val);
    }
}

// Function to initialize the queue dynamically
struct queue* createQueue(int size) {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue)); // Allocate memory for the queue
    if (q == NULL) {
        printf("Memory allocation failed for the queue structure!\n");
        exit(1); 
    }

    q->size = size; 
    q->f = 0; // Initialize front to 0
    q->r = 0; // Initialize rear to 0

    // Allocate memory for the queue's dynamic array
    q->arr = (int*)malloc(q->size * sizeof(int));
    if (q->arr == NULL) {
        printf("Memory allocation failed for the queue array!\n");
        free(q);
        exit(1);
    }

    return q; // Return the created queue
}

int main() {
    struct queue *q; 
    int size, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &size); // Read the size of the queue

    // Create the queue dynamically with the given size
    q = createQueue(size);

    // Enqueue elements dynamically
    char choice;
    do {
        printf("Enter a value to enqueue: ");
        scanf("%d", &value);
        enqueue(q, value);

        printf("Do you want to enqueue another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Free allocated memory
    free(q->arr); 
    free(q);

    return 0;
}
