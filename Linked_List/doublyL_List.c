#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *header; //declare external pointer header that points to the list

struct node *getNode(int data) {
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("\nMemory Allocation failed.");
        getch();
        exit(0);
    }

    ptrnew->info = data;
    ptrnew->prev = ptrnew->next = NULL;
    return ptrnew;
}

void insertAtBeginning() {
    int data;
    struct node *newNode;

    printf("Enter a number: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (header == NULL){ // Empty list
        header = newNode;
        printf("Inserted at the front.\n");
    } else {
        newNode->next = header;
        header->prev = newNode;
        header = newNode;
        printf("Inserted at the beginning.\n");
    }
}


void insertAtEnd() {
    int data;
    struct node *newNode, *ptrThis;

    printf("Enter a number: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (header == NULL) { //empty list
        header = newNode;
        printf("Inserted at the end.\n");
    } else {
        ptrThis=header;
        while (ptrThis->next!=NULL)
        {
            /* code */
            ptrThis=ptrThis->next;
        }
        ptrThis->next = newNode;
        newNode->prev = ptrThis;
        printf("Inserted at the end.\n");
    }
}

void insertAfterKey(int key) {
    int data;
    printf("Enter the data to insert: ");
    scanf("%d", &data);

    struct node *ptrThis = header;
    while (ptrThis != NULL)
    {
        if (ptrThis->info == key) 
        {
            // Create a new node
            struct node *newNode = getNode(data);

            // Insert the new node after the key node
            newNode->next = ptrThis->next;
            if (ptrThis->next != NULL) 
            {
                (ptrThis->next)->prev = newNode;      //to point the prev node after new node to the new node
            }
            ptrThis->next = newNode;
            newNode->prev = ptrThis;

            printf("Inserted %d after the key %d.\n", data, key);
            return;
        }
        ptrThis = ptrThis->next;
    }

    // If key not found, print a message
    printf("Key not found in the list.\n");
}


void removeFromFront() {
    if (header == NULL)
        printf("List is empty.\n");
    else {
        int data = header->info;
        if (header->next == NULL) { //if single item in the list
            free(header);
            header = NULL;
        } else {
            header = header->next;
            free(header->prev);
            header->prev = NULL;
        }
        printf("%d was removed from the front.\n", data);
    }
}

void deleteByKey(int key) {
    if (header == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptrThis = header;
    while (ptrThis != NULL) {
        if (ptrThis->info == key) {
            // If the key node is the header node
            if (ptrThis == header) {
                header = ptrThis->next;
                if (header != NULL) {
                    header->prev = NULL;
                }
                free(ptrThis); 
                printf("Node with key %d deleted.\n", key);
                return;
            }

            // If the key node is in between
            if (ptrThis->next != NULL) {
                ptrThis->prev->next = ptrThis->next;
                ptrThis->next->prev = ptrThis->prev;
                free(ptrThis);
                printf("Node with key %d deleted.\n", key);
                return;
            }

            // If the key node is the last node
            ptrThis->prev->next = NULL;
            free(ptrThis);  
            printf("Node with key %d deleted.\n", key);
            return;
        }
        ptrThis = ptrThis->next;
    }

    printf("Key not found in the list.\n");
}


void display() {
    struct node *ptrThis;
    if (header == NULL)
        printf("List is empty.\n");
    else {
        printf("\nList contains: \n");
        for (ptrThis = header; ptrThis != NULL; ptrThis = ptrThis->next)
            printf("%d\t", ptrThis->info);
    }
}

int main() {
    char choice;
    int key;
    header = NULL; //initialize empty list;

    do {
        printf("\nSelect Your Choice: ");
        printf("\n1. InsertAtBeginning \n2. InsertAtEnd \n3. InsertAfterAny \n4. RemoveFromFront \n5. RemoveAny \n6. Display \n7. Exit\n");
        fflush(stdin);
        choice = getch();
        switch (choice) {

            case '1': 
                insertAtBeginning();
                break;

            case '2':
                insertAtEnd();
                break;

            case '3':
                printf("Enter the key element: ");
                scanf("%d", &key);
                insertAfterKey(key);
                break;

            case '4':
                removeFromFront();
                break;

            case '5':
                printf("Enter the key element to delete: ");
                scanf("%d", &key);
                deleteByKey(key);
                break;

            case '6':
                display();
                break;

            case '7':
                return 0;

            default:
                printf("Wrong Selection. Try Again.\n");
        }
    } while (1);
    return 0;
}
 