#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *header; //declare external pointer header that points to the list

struct node *getNode(int data)
{
    struct node *ptrnew;
    ptrnew=(struct node *)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("\nMemory Allocation failed.");
        getch();
        exit(0);
    }

    ptrnew->info=data;
    ptrnew->prev=ptrnew->next=NULL;
    return ptrnew;
}

void insertAtEnd()
{
    int data;
    struct node *newNode, *ptrThis;

    printf("Enter a number: ");
    scanf("%d", &data);
    newNode=getNode(data);

    if(header==NULL)        //empty list
    {
        header=newNode;
        printf("inserted at the front.");
    }

    else{
            newNode->next=header;
            header->prev=newNode;
            header=newNode;
        }
}

void insertAfter()
{
    struct node *newNode, *ptrThis;
    int data , key;
    if(header=NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a key number after which you want to insert new node.: ");
        scanf("%d", &key);
        for(ptrThis=header; ptrThis!=NULL; ptrThis=ptrThis->next)
        {
            if(ptrThis->info==key)      //if the node is found
            {
                printf("Ënter a number to be inserted: ");
                scanf("%d", &data);
                newNode=getNode(data);
                newNode->next=ptrThis->next;
                newNode->prev=ptrThis;

                if(ptrThis->next!=NULL)     //if we ate addint in the middle
                    (ptrThis->next)->prev=newNode;

                (ptrThis->next)->prev=newNode;
                ptrThis->next=newNode;
                printf("Inserted after %d", ptrThis->info);
                return;
            }
        }
        printf("Node not found with the key value %d", key);
    }
}

void insertBeforeKey()
{
    struct node *newNode, *ptrThis;
    int data , key;
    if(header=NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a key number after which you want to insert new node.: ");
        scanf("%d", &key);
        for(ptrThis=header; ptrThis!=NULL; ptrThis=ptrThis->next)
        {
            if(ptrThis->info==key)     //if the node is found
            {
                printf("Enter a number to be inserted: ");
                scanf("%d", &data);
                newNode=getNode(data);
                newNode->next=ptrThis->next;
                newNode->prev=ptrThis;

                if(ptrThis->next!=NULL)     //if we ate addint in the middle
                    (ptrThis->next)->prev=newNode;

                (ptrThis->next)->prev=newNode;
                ptrThis->next=newNode;
                printf("Inserted after %d", ptrThis->info);
                return;
            }
        }
        printf("Node not found with the key value %d", key);
    }
}


    printf("Enter the key value before which you want to insert a new node: ");
    scanf("%d", &key);

    for(ptrThis = header; ptrThis != NULL; ptrThis = ptrThis->next)
    {
        if(ptrThis->info == key) // If the node is found
        {
            printf("Enter the number to be inserted: ");
            scanf("%d", &data);

            newNode = getNode(data);
            newNode->next = ptrThis;
            newNode->prev = ptrThis->prev;

            if(ptrThis->prev != NULL) // If we are inserting in the middle or at the start
                ptrThis->prev->next = newNode;
            else // If we are inserting at the start
                header = newNode;

            ptrThis->prev = newNode;
            printf("Inserted before %d", ptrThis->info);
            return;
        }
    }

    printf("Node not found with the key value %d", key);
}


void removeFromFront()
{
    //struct node *header;
    if(header==NULL)
        printf("List is empty.");

    else
    { 
         int data = header->info;
        if(header->next==NULL)        //if single item in the list
        {
            /* code */
            free(header);
            header=NULL;
        }
        

        else
        {
            header=header->next;
            header=header->next;
            free(header->prev);
        }
        printf("%d was removed from the front.", data);
    }
}

void display()
{
    struct node *ptrthis;
    if (header==NULL)
        printf("List is empty.\n");
    
    else
    {
        printf("\nList contains: \n");
        for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
            printf("%d\t", ptrthis->info);
    }
}

void main()
{
    char choice;
    header=NULL;    //initialize empty list;

    do{
        printf("Select Your Choice: ");
        printf("\n1.Insert At End \n2.Remove From Front \n3.Display \n4.Exit \n5.Insert Before Key\n");

        fflush(stdin);
        choice=getche();
        switch(choice)
        {
            case '1': insertAtEnd();
                        break;
        
            case '2': removeFromFront();
                        break;
            
            case '3': display();
                        break;

            case '4': return;

            case '5': insertBeforeKey();
                        break;


            default: ("Wrong Selection. Try Again.\n");
        }
        getch();   
    }
    while(1);
    getch();
}