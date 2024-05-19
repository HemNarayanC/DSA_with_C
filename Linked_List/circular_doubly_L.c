#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *header;            //global pointer

struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew=(struct node *)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("Memory Allocation Failed.");
        getch();
        exit(0);
    }
    ptrnew->info=n;
    ptrnew->next=NULL;
    ptrnew->prev=NULL;
    return ptrnew;
}

void insertAtFront()
{
    int n;
    struct node *ptrnew;
    printf("Enter a number: ");
    scanf("%d", &n);
    ptrnew=getnode(n);
    if(header==NULL)        //if new node is the only node in the list
    {
        header=ptrnew;
        ptrnew->next=ptrnew;
        ptrnew->prev=ptrnew;
    }

    else        //if list already contains one or many items
    {
        ptrnew->next=header->next;
        ptrnew->prev=header;
        (header->next)->prev=ptrnew;
        header->next=ptrnew;
    }
    printf("Item inserted at the front.\n");
}

void insertAtEnd()
{
    int n;
    struct node *ptrnew;
    printf("Enter a number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL) // if new node is the only node in the list
    {
        header = ptrnew;
        ptrnew->next = ptrnew;
        ptrnew->prev = ptrnew;
    }
    else // if list already contains one or many items
    {
        ptrnew->next=header->next;
        ptrnew->prev=header;
        header->next=ptrnew;
        (header->next)->prev=ptrnew;
        header=ptrnew;
        // ptrnew->prev = header->prev;
        // ptrnew->next = header;
        // (header->prev)->next = ptrnew;
        // header->prev = ptrnew;
    }
    printf("Item inserted at the end.\n");
}

void insertAfter()
{
    int key, n;
    struct node* ptrThis, *ptrnew;
    if(header==NULL)
        printf("\nList is empty.");
    else    //if list contains some items
    {
        printf("\nEnter a key number: ");
        scanf("%d", &key);
        ptrThis=header->next;       //start from first node
        do
        {
            /* code */
            if(ptrThis->info==key)      //if node found then insert after it and then return
            {
                //write your insert logic here
                printf("\nEnter new number you want to insert: ");
                scanf("%d", &n);
                ptrnew=getnode(n);
                ptrnew->prev=ptrThis;
                ptrnew->next=ptrThis->next;
                (ptrThis->next)->prev=ptrnew;
                ptrThis->next=ptrnew;

                if(ptrThis==header)     //if we are inserting after last node, then make new node as last node 
                    header=header->next;
                return;
            }
            ptrThis=ptrThis->next;      //move to next node
        } while (ptrThis!=header->next);
        printf("\nKey not found.");
    }

}

// void insertAfter()
// {
//     int key, n;
//     struct node *ptrnew, *ptrthis;
//     if (header == NULL)
//     {
//         printf("List is empty. Cannot insert after.\n");
//         return;
//     }
//     printf("Enter the key after which you want to insert: ");
//     scanf("%d", &key);
//     printf("Enter the number to insert: ");
//     scanf("%d", &n);
//     ptrnew = getnode(n);
//     ptrthis = header;
//     do
//     {
//         if (ptrthis->info == key)
//         {
//             ptrnew->next = ptrthis->next;
//             ptrnew->prev = ptrthis;
//             (ptrthis->next)->prev = ptrnew;
//             ptrthis->next = ptrnew;
//             printf("Item inserted after %d.\n", key);
//             return;
//         }
//         ptrthis = ptrthis->next;
//     } while (ptrthis != header);
//     printf("Key not found. Cannot insert after.\n");
// }

void insertBefore()
{
    int key, n;
    struct node* ptrThis, *ptrnew;
    if(header==NULL)
        printf("\nList is empty.");
    else    //if list contains some items
    {
        printf("\nEnter a key number: ");
        scanf("%d", &key);
        ptrThis=header->next;       //start from first node
        do
        {
            /* code */
            if(ptrThis->info==key)      //if node found then insert after it and then return
            {
                //write your insert logic here
                printf("\nEnter new number you want to insert before: ");
                scanf("%d", &n);
                ptrnew=getnode(n);
                ptrnew->prev=ptrThis->prev;
                ptrnew->next=ptrThis;
                (ptrThis->prev)->next=ptrnew;
                ptrThis->prev=ptrnew;
                return;
            }
            ptrThis=ptrThis->next;      //move to next node
        } while (ptrThis!=header->next);
        printf("\nKey not found.");
    }
}

void removeFront()
{
    struct node *ptrThis;
    if(header==NULL)
    {
        printf("List is empty.");
    }

    else if(header==header->next)
    {
        free(header);
        header=NULL;
        printf("\nRemoved from front.");
    }

    else
    {
        ptrThis=header->next;
        header->next=ptrThis->next;
        (ptrThis->next)->prev=header;
        free(ptrThis);
        printf("\nRemoved from front.");
    }
}

// void removeEnd()
// {
//     struct node *ptrThis;
//     if(header==NULL)
//     {
//         printf("List is empty.");
//     }

//     else if(header==header->next)
//     {
//         free(header);
//         header=NULL;
//         printf("\nRemoved from End.");
//     }

//     else
//     {
//         header=header->prev;
//         ptrThis=header->next;
//         header->next=ptrThis->next;
//         (ptrThis->next)->prev=header;
//         free(ptrThis);
//         printf("\nRemoved from End.");
//     }
// }

void removeEnd()
{
    struct node *ptrThis;
    if (header == NULL)
    {
        printf("List is empty.");
    }
    else if (header == header->next) // Only one node in the list
    {
        free(header);
        header = NULL;
        printf("\nRemoved from End.");
    }
    else
    {
        ptrThis = header->prev;
        header->prev = ptrThis->prev;
        (ptrThis->prev)->next = header;
        free(ptrThis);
        printf("\nRemoved from End.");
    }
}


void removeAny()
{
    int key, n;
    struct node* ptrThis, *ptrnew;
    if(header==NULL)
        printf("\nList is empty.");
    else    //if list contains some items
    {
        printf("\nEnter a key number: ");
        scanf("%d", &key);
        ptrThis=header->next;       //start from first node
        do
        {
            /* code */
            if(ptrThis->info==key)      //if node found then insert after it and then return
            {
                (ptrThis->prev)->next=ptrThis->next;
                (ptrThis->next)->prev=ptrThis->prev;

                if(ptrThis==header)     //if we are inserting after last node, then make new node as last node 
                    header=header->prev;
                printf("%d is deleted from the list.", key);
                return;
            }
            ptrThis=ptrThis->next;      //move to next node
        } while (ptrThis!=header->next);
        printf("\nKey not found.");
    }
}

void display()
{
    struct node *ptrthis;
    if(header==NULL)
    {
        printf("\nList is empty.");
    }

    else
    {
        printf("\nList contains: \n");
        ptrthis=header->next;  //point to the first node
        do
        {
            /* code */
            printf("%d\t", ptrthis->info);
            ptrthis=ptrthis->next;
        }while(header!=ptrthis->next);
    }
}

void main()
{
    char choice;
    header=NULL;        //initially list is empty
    do
    {
        /* code */
        printf("\nSelect an option:\n1.Insert at front\n2.Insert at end\n3.Insert after\n4.Insert Before\n5.Remove from front\n6.Remove from end\n7.Remove any\n8.Display\n9.Exit\n");
        fflush(stdin);          //this is needed to clear any pending keystrokes
        choice=getch();
        switch(choice)
        {
            case '1': insertAtFront();
                    break;
            case '2': insertAtEnd();
                    break;
            case '3': insertAfter();
                    break;
            case '4': insertBefore();
                    break;
            case '5': removeFront();
                    break;
            case '6': removeEnd();
                    break;
            case '7': removeAny();
                    break;
            case '8':
                    display();
                    break;
            case '9':
                    printf("\nIt is time to go away. Good Bye");
                    getch();
                    return;
        }
        //getch();        //this is needed to hold the output
    } while (1);   
}