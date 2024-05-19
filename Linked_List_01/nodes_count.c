
//Counting the number of nodes in a linked list in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void printData(struct node *head)
{
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
        exit(1);
    }
    
    struct node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->info);
        ptr=ptr->next;
    }
}

int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->info=60;
    head->next=NULL;

    // Creating the second node and linking it to the head
    struct node *ptrThis=(struct node *)malloc(sizeof(struct node));
    ptrThis->info=70;
    ptrThis->next=NULL;
    head->next=ptrThis;

    // Creating the third node and linking it to the second node
    ptrThis=malloc(sizeof(struct node));
    ptrThis->info=50;
    ptrThis->next=NULL;
    (head->next)->next=ptrThis;

    // Creating the fourth node and linking it to the third node
    ptrThis=malloc(sizeof(struct node));
    ptrThis->info=100;
    ptrThis->next=NULL;
    ((head->next)->next)->next=ptrThis;

    printData(head);
    return 0;
}