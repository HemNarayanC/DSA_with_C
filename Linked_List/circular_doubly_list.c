#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *header;

struct node *getnode(int);
void insertAtFront();
void insertAtEnd();
void insertAfter();
void removeFromFront();
void removeFromEnd();
void removeAny();
void display();

int main()
{
    char choice;
    header = NULL; // initialize empty list

    do
    {
        printf("\nSelect an option:\n1. Insert at front\n2. Insert at end");
        printf("\n3. Insert after\n4. Remove from front\n5. Remove from end");
        printf("\n6. Remove any\n7. Display list\n8. Exit\n");
        fflush(stdin);
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAtEnd();
            break;
        case '3':
            insertAfter();
            break;
        case '4':
            removeFromFront();
            break;
        case '5':
            removeFromEnd();
            break;
        case '6':
            removeAny();
            break;
        case '7':
            display();
            break;
        case '8':
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (1);

    return 0;
}

struct node *getnode(int n)
{
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->next = NULL;
    ptrnew->prev = NULL;
    return ptrnew;
}

void insertAtFront()
{
    int data;
    printf("Enter a number:");
    scanf("%d", &data);
    struct node *ptrnew = getnode(data);

    if (header == NULL)
    {
        header = ptrnew;
        header->next = header;
        header->prev = header;
    }
    else
    {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
        header = ptrnew;
    }
    printf("Item inserted at the front.");
}

void insertAtEnd()
{
    int data;
    printf("Enter a number:");
    scanf("%d", &data);
    struct node *ptrnew = getnode(data);

    if (header == NULL)
    {
        header = ptrnew;
        header->next = header;
        header->prev = header;
    }
    else
    {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
    }
    printf("Item inserted at the end.");
}

void insertAfter()
{
    int data, key;
    printf("Enter a number after which you want to insert:");
    scanf("%d", &key);

    if (header == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct node *ptrthis = header;
    do
    {
        if (ptrthis->info == key)
        {
            printf("Enter new number:");
            scanf("%d", &data);
            struct node *ptrnew = getnode(data);
            ptrnew->next = ptrthis->next;
            ptrnew->prev = ptrthis;
            ptrthis->next->prev = ptrnew;
            ptrthis->next = ptrnew;
            printf("Item inserted after %d", key);
            return;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != header);

    printf("%d does not exist in the list.", key);
}

void removeFromFront()
{
    if (header == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct node *ptrthis = header;

    if (header->next == header) // Single node in the list
    {
        header = NULL;
    }
    else
    {
        header->prev->next = header->next;
        header->next->prev = header->prev;
        header = header->next;
    }

    free(ptrthis);
    printf("Item removed from front.");
}

void removeFromEnd()
{
    if (header == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct node *ptrthis = header->prev;

    if (header->next == header) // Single node in the list
    {
        header = NULL;
    }
    else
    {
        header->prev = ptrthis->prev;
        ptrthis->prev->next = header;
    }

    free(ptrthis);
    printf("Item removed from End.");
}

void removeAny()
{
    int key;
    printf("Enter a number you want to delete: ");
    scanf("%d", &key);

    if (header == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct node *ptrthis = header;
    do
    {
        if (ptrthis->info == key)
        {
            if (ptrthis == header)
                header = header->next;
            ptrthis->prev->next = ptrthis->next;
            ptrthis->next->prev = ptrthis->prev;
            free(ptrthis);
            printf("Item removed from the list");
            return;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != header);

    printf("%d does not exist in the list.", key);
}

void display()
{
    if (header == NULL)
    {
        printf("List is empty.");
        return;
    }

    printf("\nList contains:\n");
    struct node *ptrthis = header;
    do
    {
        printf("%d\t", ptrthis->info);
        ptrthis = ptrthis->next;
    } while (ptrthis != header);
}
