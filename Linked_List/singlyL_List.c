#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define a structure for a node
struct node {
    int info;
    struct node *next;
};

struct node *header; // Declare external pointer header that points to the list

// Function to create a new node
struct node *getNode(int data) {
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("\nMemory Allocation failed.");
        exit(0);
    }

    ptrnew->info = data;
    ptrnew->next = NULL;
    return ptrnew;
}

void insertAtBeginning() {
    int data;
    struct node *newNode;

    printf("Enter a number: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (header == NULL) { // Empty list
        header = newNode;
    } else {
        newNode->next = header;
        header = newNode;
    }
    printf("Inserted at the beginning.\n");
}


// Function to insert a node at the end of the list
void insertAtEnd() {
    int data;
    struct node *newNode, *ptrThis;

    printf("Enter a number: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (header == NULL) { // Empty list
        header = newNode;
    } else {
        ptrThis = header;
        while (ptrThis->next != NULL) {
            ptrThis = ptrThis->next;
        }
        ptrThis->next = newNode;
    }
    printf("Inserted at the end.\n");
}

// Function to remove a node from the front of the list
void removeFromFront() {
    if (header == NULL) {
        printf("List is empty.\n");
    } else {
        int data = header->info;
        struct node *temp = header;
        header = header->next; 
        free(temp);
        printf("%d was removed from the front.\n", data);
    }
}

void removeFromEnd() {
    if (header == NULL) {
        printf("List is empty.\n");
    } else if (header->next == NULL) { // Only one node in the list
        free(header);
        header = NULL;
        printf("Removed from end.\n");
    } else {
        struct node *ptrThis = header;
        struct node *prevNode = NULL;

        // Traverse until the last node
        while (ptrThis->next != NULL) {
            prevNode = ptrThis;
            ptrThis = ptrThis->next;
        }

        // Update the next pointer of the second-to-last node to NULL
        prevNode->next = NULL;

        // Free the memory allocated for the last node
        free(ptrThis);

        printf("Removed from end.\n");
    }
}


// Function to display the elements of the list
void display() {
    struct node *ptrThis;
    if (header == NULL) {
        printf("List is empty.\n");
    } else {
        printf("\nList contains: \n");
        for (ptrThis = header; ptrThis != NULL; ptrThis = ptrThis->next) {
            printf("%d\t", ptrThis->info);
        }
        printf("\n");
    }
}


int main() {
    char choice;
    header = NULL; // Initialize empty list

    do {
        printf("\nSelect Your Choice: ");
        printf("\n1. InsertAtEnd \n2. InsertAtBeginning \n3. RemoveFromFront \n4. RemoveFromEnd \n5. Display \n6. Exit\n");


        fflush(stdin);
        choice=getch();
        switch (choice) {
            case '1':
                insertAtEnd();
                break;
            
            case '2':
                insertAtBeginning();
                break;

            case '3':
                removeFromFront();
                break;

            case '4':
                removeFromEnd();
                break;

            case '5':
                display();
                break;

            case '6':
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Wrong Selection. Try Again.\n");
        }
    } while (1);

    return 0;
}
