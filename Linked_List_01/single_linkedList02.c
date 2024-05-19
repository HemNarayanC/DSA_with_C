
//Linked list creation and traversal in C with memory address representation 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    // Creating the head node
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=60;
    head->next=NULL;

    // Creating the second node and linking it to the head
    struct node *ptrThis=(struct node *)malloc(sizeof(struct node));
    ptrThis->data=70;
    ptrThis->next=NULL;
    head->next=ptrThis;

    // Creating the third node and linking it to the second node
    ptrThis=malloc(sizeof(struct node));
    ptrThis->data=50;
    ptrThis->next=NULL;
    (head->next)->next=ptrThis;

    // Creating the fourth node and linking it to the third node
    ptrThis=malloc(sizeof(struct node));
    ptrThis->data=100;
    ptrThis->next=NULL;
    ((head->next)->next)->next=ptrThis;

    // Printing the elements with links between nodes
    struct node *current = head;
    printf("%p\n", current); // Printing the memory address of the head node
    while (current != NULL)
    {
        printf("%d|", current->data); // Printing the data of the current node
        if (current->next != NULL)
            printf("%p-->", current->next); // Printing the memory address of the next node
        else
            printf("NULL"); // Printing NULL for the last node
        current = current->next;
    }
    return 0;
}
