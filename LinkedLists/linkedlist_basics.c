#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create_list(struct node *head);
void display_list(struct node *head);
void search_list(struct node *head);
void replace_list(struct node *head);
void insert_list(struct node *head);

int main () {
    struct node *n1;
    n1 = (struct node*)malloc(sizeof(struct node));
    
    create_list(n1);
    display_list(n1);
    // search_list(n1);
    // replace_list(n1);
    // display_list(n1);
    insert_list(n1);
    display_list(n1);

    return 0;
}

void create_list(struct node *head) {
    struct node *current;
    current = head;
    int size = 0, i = 1;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    while (i <= size) {
        printf("Enter element [%d]:", i);
        scanf("%d", &current->data);
        if (i == size) {
            // If last node
            current->next = 0;
        } else {
            // If not last node, create a new node and move LL ahead
            current->next = (struct node*)malloc(sizeof(struct node));
            current = current->next;
        }

        i++;
    }

}

void display_list(struct node *head) {
    struct node *current;
    current = head;
    printf("List-> ");
    while  (current != 0) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void search_list(struct node *head) {
    printf("---Searching a value---\n");
    struct node *current;
    current = head;
    int value, count = 0;

    printf("Enter value to search:");
    scanf("%d", &value);

    while (current != 0) {
        if (current->data == value) {
            count++;
        }
        current = current->next;
    }
    printf("%d found %d times.\n", value, count);
}

void replace_list(struct node *head) {
    printf("---Replacing a value---\n");
    struct node *current;
    current = head;
    int searchVal, replaceVal, count = 0;

    printf("Enter search value:");
    scanf("%d", &searchVal);
    printf("Enter replace value:");
    scanf("%d", &replaceVal);
    while (current != 0) {
        if (current->data == searchVal) {
            count++;
            current->data = replaceVal;
        }
        current = current->next;
    }
    
}

void insert_list(struct node *head) {
     printf("---Inserting a value---\n");
    struct node *current;
    current = head;

    int length = 0, position, value;
    // List replacement can be within list + @head + @tail

    // Find length
    while (current != 0) {
        length++;
        current = current->next;
    }
    printf("Enter position to insert (1 to %d): ", length+1);
    scanf("%d", &position);
    printf("Enter new data: ");
    scanf("%d", &value);

    //current was at the end now, so,
    current = head;

    // Inserting a new node, so,
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (position == 1) {
        // New head (can't modify head pointer)
        // So newnode is now 2nd node, but exchange previous head and newnode values
        printf("Inserting at head\n");
        newnode->next = current->next; // new node has old head's details
        newnode->data = current->data;
        current->next = newnode; // add new value to head andre-wire
        current->data = value;

    } else if (position == (length+1)) {
        printf("Inserting at tail\n");
        while (current->next != 0) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = 0;
        newnode->data = value;

    } else {
        printf("Inserting in between\n");
        int i = 1;
        while(i < position-1) { // Already LL is at head, so 1 less to traverse
            current = current->next;
            i++;
        }
        newnode->next = current->next;
        newnode->data = value;
        current->next = newnode;
        
    }

}