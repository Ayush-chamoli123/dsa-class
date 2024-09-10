    #include <stdio.h>
    #include <stdlib.h>

// Definition of the linked list node
      struct node {
      int data;
      struct node *next;
       };
       struct node* delete_end(struct node* start) {
       struct node* ptr, *temp;
       if (start == NULL) {
       printf("The list is already emptyNothing to delete.\n");
       return start;
       }
       if (start->next == NULL) {
       free(start);
       start = NULL;
       printf("The last node has been deleted.\n");
       return start;
       }
       ptr = start;
       while (ptr->next->next != NULL) {
       ptr = ptr->next;
       }
       temp = ptr->next;
       ptr->next = NULL;
       free(temp);       
       return start;     
       }

       struct node* delete_beg(struct node* start) {
       struct node* ptr;
       if (start == NULL) {
       printf("The list is already empty. Nothing to delete.\n");
       return start;
       }
       ptr = start;
       start = start->next;
       free(ptr);
       return start;
       }
       struct node* insert_after(struct node* start) {
       int num, val;
       struct node* newnode, *ptr;

       printf("Enter the data to insert: ");
       scanf("%d", &num);
       printf("Enter the value before which to insert: ");
       scanf("%d", &val);
       newnode = (struct node*)malloc(sizeof(struct node));
       newnode->data = num;
       if (start == NULL) {
       printf("The list is empty. Cannot insert before value %d.\n", val);
       free(newnode);
       return start;
       }
       if (start->data == val) {
       newnode->next = start;
       start = newnode;
       return start;
       }
       ptr = start;
       while (ptr != NULL && ptr->data != val) {
       ptr = ptr->next;
       }
       if (ptr == NULL) {
       printf("Value %d not found in the list. Insertion not possible.\n", val);
       free(newnode);  
       return start;
       }
       newnode->next = ptr->next;
       ptr->next = newnode;
       return start;
       }

       struct node* insert_before(struct node* start) {
       int num, val;
       struct node* newnode, *ptr, *ptr1;

       printf("Enter the data to insert: ");
       scanf("%d", &num);
       printf("Enter the value before which to insert: ");
       scanf("%d", &val);
       newnode = (struct node*)malloc(sizeof(struct node));
       newnode->data = num;
       if (start == NULL) {
       printf("The list is empty. Cannot insert before value %d.\n", val);
       free(newnode);
       return start;
       }
       if (start->data == val) {
       newnode->next = start;
       start = newnode;
       return start;
       }
       ptr1 = start;
       while (ptr1 != NULL && ptr1->data != val) {
       ptr = ptr1;  // Keep track of the previous node
       ptr1 = ptr1->next;
       }

   
       if (ptr1 == NULL) {
       printf("Value %d not found in the list. Insertion not possible.\n", val);
       free(newnode);  
       return start;
       }
       newnode->next = ptr1;
       ptr->next = newnode;
       return start;
       }

       struct node* insert_end(struct node* start){
       int num;
       struct node * newnode, *ptr;
       printf("enter data ");
       scanf("%d",&num);
       newnode=(struct node*)malloc(sizeof(struct node));
       if(start==NULL){
        start=newnode;
       }else{
       ptr=start;
       }
       while(ptr->next!=NULL){
       ptr=ptr->next;
       }
       newnode->next=NULL;
       newnode->data=num;
       ptr->next=newnode;
       return start;
       }
       struct node *insert_beg(struct node* ptr){
       struct node *newnode;
       int num;
       printf("enter data ");
       scanf("%d",&num);
       newnode=(struct node*)malloc(sizeof(struct node));
       newnode->data=num;
       newnode->next=ptr;
       ptr=newnode;
       return ptr;
       }
       struct node* display(struct node* ptr){
       printf("linked list\n");
       while(ptr!=NULL){
       printf("%d ",ptr->data);
       ptr=ptr->next;
       }
       }
// Function to create a linked list
        struct node *create(struct node *start) {
        struct node *newnode, *ptr=start;
        int num;
        printf("Enter -1 to end\n");
        printf("Enter the data: ");
        scanf("%d", &num);

    // While the user does not enter -1, keep creating nodes
        while (num != -1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        
        if (start == NULL) {
        start = newnode;  // If the list is empty, start points to the new node
        } else {
        ptr = start;
        while (ptr->next != NULL) {
        ptr = ptr->next;  // Traverse to the end of the list
            }
        ptr->next = newnode;  // Append the new node at the end
        }
        printf("Enter the data: ");
        scanf("%d", &num);
        }
        return start;
        }
        int main()
        {
        int option;
        struct node *start = NULL;  // Initialize the start pointer to NULL
        do 
        {
        printf("\n**** MENU ****\n");
        printf("1: Create a Linked List\n");
        printf("13: Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) 
        {
        case 1:
        start = create(start);
        printf("\nLinked list created.\n");
        break;
        case 2:
        start = display(start);
        break;
        case 3:
        start = insert_beg(start);
        printf("insert at begning");
        break;
        case 4:
        printf("insert at end");
        start= insert_end(start);
        break;
        case 5:
        printf("insert before given value");
        start=insert_before(start);
        break;
        case 6:
        printf("insert after givne value: \n");
        start=insert_after(start);
        break;
        case 7:
        printf("delete element from beg :\n");
        start= delete_beg(start);
        break;
        case 8:
        printf("delete from end");
        start=delete_end(start);
        break;
        }
        }
        while (option != 11);
        return 0;
        }