#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure to represent an item in the list
struct Item {
    int id;
    char name[100];
    int phone;
    char address[100];
};

// Define the list structure
struct List {
    struct Item items[MAX_SIZE];
    int size;
};

// Function to initialize the list
void initList(struct List *list) {
    list->size = 0;
}

// Function to insert an item at the front of the list
void insertFront(struct List *list, struct Item item) {
    if (list->size < MAX_SIZE) {
        for (int i = list->size; i > 0; i--) {
            list->items[i] = list->items[i - 1];
        }
        list->items[0] = item;
        list->size++;
    } else {
        printf("List is full, cannot insert.\n");
    }
}

// Function to insert an item at the end of the list
void insertEnd(struct List *list, struct Item item) {
    if (list->size < MAX_SIZE) {
        list->items[list->size] = item;
        list->size++;
    } else {
        printf("List is full, cannot insert.\n");
    }
}

// Function to insert an item after a specified item
void insertAfter(struct List *list, struct Item item, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->items[i].id == id) {
            if (list->size < MAX_SIZE) {
                for (int j = list->size; j > i + 1; j--) {
                    list->items[j] = list->items[j - 1];
                }
                list->items[i + 1] = item;
                list->size++;
            } else {
                printf("List is full, cannot insert.\n");
            }
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

// Function to insert an item before a specified item
void insertBefore(struct List *list, struct Item item, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->items[i].id == id) {
            if (list->size < MAX_SIZE) {
                for (int j = list->size; j > i; j--) {
                    list->items[j] = list->items[j - 1];
                }
                list->items[i] = item;
                list->size++;
            } else {
                printf("List is full, cannot insert.\n");
            }
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

// Function to remove an item from the front of the list
void removeFront(struct List *list) {
    if (list->size > 0) {
        for (int i = 0; i < list->size - 1; i++) {
            list->items[i] = list->items[i + 1];
        }
        list->size--;
    } else {
        printf("List is empty, cannot remove.\n");
    }
}

// Function to remove an item from the end of the list
void removeEnd(struct List *list) {
    if (list->size > 0) {
        list->size--;
    } else {
        printf("List is empty, cannot remove.\n");
    }
}

// Function to remove a specified item from the list
void removeItem(struct List *list, int id) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->items[i].id == id) {
            for (int j = i; j < list->size - 1; j++) {
                list->items[j] = list->items[j + 1];
            }
            list->size--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

// Function to list all items in the list
void listItems(struct List *list) {
    if (list->size == 0) {
        printf("List is empty.\n");
    } else {
        printf("Items in the list:\n");
        for (int i = 0; i < list->size; i++) {
            printf("ID: %d, Name: %s, Phone: %d, Address: %s\n", list->items[i].id, list->items[i].name, list->items[i].phone, list->items[i].address);
        }
    }
}

// Function to search for an item by ID
void searchItemByID(struct List *list, int id) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->items[i].id == id) {
            printf("Item found: ID: %d, Name: %s, Item Phone: %d, Address: %s\n", list->items[i].id, list->items[i].name, list->items[i].phone, list->items[i].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

// Function to search for an item by name
void searchItemByName(struct List *list, const char *name) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->items[i].name, name) == 0) {
            printf("Item found: ID: %d, Name: %s, Phone: %d, Address: %s\n", list->items[i].id, list->items[i].name, list->items[i].phone, list->items[i].address);
            found = 1;
            // If you want to search for multiple items with the same name, comment out the break statement
            break;
        }
    }
    if (!found) {
        printf("Item with name '%s' not found.\n", name);
    }
}

int main() {
    struct List list;
    initList(&list);

    int choice;
    struct Item newItem;
    int id;
    char name[50];
    int phone;
    char address[100];

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. List items\n");
        printf("4. Search item by ID\n");
        printf("5. Search item by Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &newItem.id);
                printf("Enter item name: ");
                scanf("%s", newItem.name);
                printf("Enter item phone: ");
                scanf("%d", &newItem.phone);
                printf("Enter item address: ");
                scanf("%s", newItem.address);
                printf("Where to insert?\n");
                printf("1. Front\n");
                printf("2. End\n");
                printf("3. After an item\n");
                printf("4. Before an item\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        insertFront(&list, newItem);
                        break;
                    case 2:
                        insertEnd(&list, newItem);
                        break;
                    case 3:
                        printf("Enter ID of the item after which to insert: ");
                        scanf("%d", &id);
                        insertAfter(&list, newItem, id);
                        break;
                    case 4:
                        printf("Enter ID of the item before which to insert: ");
                        scanf("%d", &id);
                        insertBefore(&list, newItem, id);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 2:
                printf("From where to remove?\n");
                printf("1. Front\n");
                printf("2. End\n");
                printf("3. Any item\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        removeFront(&list);
                        break;
                    case 2:
                        removeEnd(&list);
                        break;
                    case 3:
                        printf("Enter ID of the item to remove: ");
                        scanf("%d", &id);
                        removeItem(&list, id);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 3:
                listItems(&list);
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchItemByID(&list, id);
                break;
            case 5:
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchItemByName(&list, name);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

