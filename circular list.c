#include <stdio.h>
#include <stdlib.h>

// Definition of the circular linked list node
struct node {
    int data;
    struct node *next;
};

// Function to delete the last node
void delete_end(struct node **start) {
    struct node *ptr, *temp;
    if (*start == NULL) {
        printf("The list is already empty. Nothing to delete.\n");
        return;
    }
    if ((*start)->next == *start) {  // Only one node
        free(*start);
        *start = NULL;
        printf("The last node has been deleted.\n");
        return;
    }
    ptr = *start;
    while (ptr->next->next != *start) {  // Traverse until the second last node
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = *start;
    free(temp);
    printf("Deleted from the end.\n");
}

// Function to delete the first node
void delete_beg(struct node **start) {
    struct node *ptr;
    if (*start == NULL) {
        printf("The list is already empty. Nothing to delete.\n");
        return;
    }
    if ((*start)->next == *start) {  // Only one node
        free(*start);
        *start = NULL;
        printf("Deleted from the beginning.\n");
        return;
    }
    ptr = *start;
    while (ptr->next != *start) {  // Traverse to the last node
        ptr = ptr->next;
    }
    struct node *temp = *start;
    ptr->next = (*start)->next;
    *start = (*start)->next;
    free(temp);
    printf("Deleted from the beginning.\n");
}

// Function to insert after a given value
void insert_after(struct node **start) {
    int num, val;
    struct node *newnode, *ptr;

    printf("Enter the data to insert: ");
    scanf("%d", &num);
    printf("Enter the value after which to insert: ");
    scanf("%d", &val);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (*start == NULL) {
        printf("The list is empty. Cannot insert after value %d.\n", val);
        free(newnode);
        return;
    }

    ptr = *start;
    do {
        if (ptr->data == val) {
            newnode->next = ptr->next;
            ptr->next = newnode;
            printf("Inserted after %d.\n", val);
            return;
        }
        ptr = ptr->next;
    } while (ptr != *start);

    printf("Value %d not found in the list. Insertion not possible.\n", val);
    free(newnode);
}

// Function to insert before a given value
void insert_before(struct node **start) {
    int num, val;
    struct node *newnode, *ptr, *prev;

    printf("Enter the data to insert: ");
    scanf("%d", &num);
    printf("Enter the value before which to insert: ");
    scanf("%d", &val);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (*start == NULL) {
        printf("The list is empty. Cannot insert before value %d.\n", val);
        free(newnode);
        return;
    }

    ptr = *start;
    prev = NULL;

    do {
        if (ptr->data == val) {
            if (prev == NULL) { // Insert at the beginning
                newnode->next = *start;
                struct node *last = *start;
                while (last->next != *start) {
                    last = last->next;
                }
                last->next = newnode;
                *start = newnode;
            } else {
                newnode->next = ptr;
                prev->next = newnode;
            }
            printf("Inserted before %d.\n", val);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    } while (ptr != *start);

    printf("Value %d not found in the list. Insertion not possible.\n", val);
    free(newnode);
}

// Function to insert at the end of the list
void insert_end(struct node **start) {
    int num;
    struct node *newnode, *ptr;

    printf("Enter data: ");
    scanf("%d", &num);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (*start == NULL) {
        *start = newnode;
        newnode->next = newnode;  // Points to itself to make it circular
    } else {
        ptr = *start;
        while (ptr->next != *start) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = *start;
    }
    printf("Inserted at the end.\n");
}

// Function to insert at the beginning of the list
void insert_beg(struct node **start) {
    int num;
    struct node *newnode, *ptr;

    printf("Enter data: ");
    scanf("%d", &num);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (*start == NULL) {
        *start = newnode;
        newnode->next = newnode;  // Points to itself to make it circular
    } else {
        ptr = *start;
        while (ptr->next != *start) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = *start;
        *start = newnode;
    }
    printf("Inserted at the beginning.\n");
}

// Function to display the circular linked list
void display(struct node *start) {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr = start;
    printf("Circular linked list: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

// Function to create a circular linked list
void create(struct node **start) {
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);

    while (num != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;

        if (*start == NULL) {
            *start = newnode;
            newnode->next = newnode;  // Points to itself
        } else {
            ptr = *start;
            while (ptr->next != *start) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = *start;
        }
        printf("Enter the data: ");
        scanf("%d", &num);
    }
}

int main() {
    int option;
    struct node *start = NULL;

    do {
        printf("\n**** MENU ****\n");
        printf("1: Create a Circular Linked List\n");
        printf("2: Display the Circular Linked List\n");
        printf("3: Insert at the Beginning\n");
        printf("4: Insert at the End\n");
        printf("5: Insert Before a Value\n");
        printf("6: Insert After a Value\n");
        printf("7: Delete from the Beginning\n");
        printf("8: Delete from the End\n");
        printf("13: Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                create(&start);
                printf("\nCircular linked list created.\n");
                break;
            case 2:
                display(start);
                break;
            case 3:
                insert_beg(&start);
                break;
            case 4:
                insert_end(&start);
                break;
            case 5:
                insert_before(&start);
                break;
            case 6:
                insert_after(&start);
                break;
            case 7:
                delete_beg(&start);
                break;
            case 8:
                delete_end(&start);
                break;
        }
    } while (option != 13);

    return 0;
}
