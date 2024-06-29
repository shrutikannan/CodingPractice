#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create_list(struct node *head);
void display_list(struct node *head);

int main () {
    struct node *n1;
    n1 = (struct node*)malloc(sizeof(struct node));
    
    create_list(n1);
        
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

