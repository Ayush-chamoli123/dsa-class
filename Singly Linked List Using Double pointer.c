#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
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
    if ((*start)->next == NULL) {
        free(*start);
        *start = NULL;
        printf("The last node has been deleted.\n");
        return;
    }
    ptr = *start;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

// Function to delete the first node
void delete_beg(struct node **start) {
    struct node *ptr;
    if (*start == NULL) {
        printf("The list is already empty. Nothing to delete.\n");
        return;
    }
    ptr = *start;
    *start = (*start)->next;
    free(ptr);
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
    newnode->next = NULL;

    if (*start == NULL) {
        printf("The list is empty. Cannot insert after value %d.\n", val);
        free(newnode);
        return;
    }

    ptr = *start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value %d not found in the list. Insertion not possible.\n", val);
        free(newnode);
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
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
    newnode->next = NULL;

    if (*start == NULL) {
        printf("The list is empty. Cannot insert before value %d.\n", val);
        free(newnode);
        return;
    }

    if ((*start)->data == val) {
    newnode->next = *start;
    *start = newnode;
    return;
    }

    ptr = *start;
    while (ptr != NULL && ptr->data != val) {
    prev = ptr;
    ptr = ptr->next;
    }

    if (ptr == NULL) {
    printf("Value %d not found in the list. Insertion not possible.\n", val);
    free(newnode);
    return;
    }

    newnode->next = ptr;
    prev->next = newnode;
}

// Function to insert at the end of the list
    void insert_end(struct node **start) {
    int num;
    struct node *newnode, *ptr;

    printf("Enter data: ");
    scanf("%d", &num);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if (*start == NULL) {
    *start = newnode;
    } else {
    ptr = *start;
    while (ptr->next != NULL) {
    ptr = ptr->next;
    }
    ptr->next = newnode;
    }
}

// Function to insert at the beginning of the list
    void insert_beg(struct node **start) {
    int num;
    struct node *newnode;

    printf("Enter data: ");
    scanf("%d", &num);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = *start;
    *start = newnode;
}

// Function to display the linked list
    void display(struct node *start) {
    printf("Linked list: ");
    while (start != NULL) {
    printf("%d ", start->data);
    start = start->next;
    }
    printf("\n");
}

// Function to create a linked list
void create(struct node **start) {
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);

    while (num != -1) {
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if (*start == NULL) {
            *start = newnode;
    } else {
    ptr = *start;
    while (ptr->next != NULL) {
    ptr = ptr->next;
    }
    ptr->next = newnode;
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
        printf("1: Create a Linked List\n");
        printf("2: Display the Linked List\n");
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
                printf("\nLinked list created.\n");
                break;
            case 2:
                display(start);
                break;
            case 3:
                insert_beg(&start);
                printf("Inserted at the beginning.\n");
                break;
            case 4:
                insert_end(&start);
                printf("Inserted at the end.\n");
                break;
            case 5:
                insert_before(&start);
                printf("Inserted before the given value.\n");
                break;
            case 6:
                insert_after(&start);
                printf("Inserted after the given value.\n");
                break;
            case 7:
                delete_beg(&start);
                printf("Deleted from the beginning.\n");
                break;
            case 8:
                delete_end(&start);
                printf("Deleted from the end.\n");
                break;
        }
    } while (option != 13);

    return 0;
}
