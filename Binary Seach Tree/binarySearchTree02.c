#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *father;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node *getnode(int n) {
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL) {
        printf("Memory Allocation Failed.\n");
        getch();
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->right = NULL;
    ptrnew->left = NULL;
    return ptrnew;
}

void bstInsert() {
    int n;
    struct node *ptrnew, *current = root, *parent = NULL;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    while (1) {
        if (current == NULL) {  // it is time to insert new node
            if (root == NULL) {  // if it is the first node in the bst, then make it root
                root = ptrnew;
                printf("%d inserted as the root node.\n", n);
            } else {  // new node will be inserted as either left or right son of parent
                if (n < parent->info) {  // insert as the left son
                    parent->left = ptrnew;
                    printf("%d inserted as the left son of %d\n", n, parent->info);
                } else {
                    parent->right = ptrnew;
                    printf("%d inserted as the right son of %d\n", n, parent->info);
                }
                ptrnew->father = parent;
            }
            return;
        } else if (n < current->info) {  // if new value is less than current node value then go to left subtree
            parent = current;
            current = current->left;
        } else {  // move to right subtree
            parent = current;
            current = current->right;
        }
    }
}

void inorder(struct node *r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%d ", r->info);
        inorder(r->right);
    }
}

void preOrder(struct node *r) {
    if (r != NULL) {
        printf("%d ", r->info);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node *r) {
    if (r != NULL) {
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->info);
    }
}

struct node *search(struct node *r, int key) {
    if (r == NULL || r->info == key) {
        return r;
    }
    if (key < r->info) {
        return search(r->left, key);
    } else {
        return search(r->right, key);
    }
}

struct node *minValueNode(struct node *n) {
    struct node *current = n;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node *deleteNode(struct node *r, int key) {
    if (r == NULL) {
        return r;
    }
    if (key < r->info) {
        r->left = deleteNode(r->left, key);
    } else if (key > r->info) {
        r->right = deleteNode(r->right, key);
    } else {
        if (r->left == NULL) {
            struct node *temp = r->right;
            free(r);
            return temp;
        } else if (r->right == NULL) {
            struct node *temp = r->left;
            free(r);
            return temp;
        }
        struct node *temp = minValueNode(r->right);
        r->info = temp->info;
        r->right = deleteNode(r->right, temp->info);
    }
    return r;
}

int main() {
    char choice;
    int key;
    root = NULL;
        printf("\nSelect an Option: \n");
        printf("1.Insert Item \n2. Remove Item \n3. Inorder Traverse");
        printf("\n4. Preorder Traverse \n5. Postorder Traverse \n6. Search Item");
        printf("\n7. Exit\n");
        fflush(stdin);
    do {
        choice = getche();
        switch (choice) {
            case '1':
                bstInsert();
                break;
            case '2':
                printf("\nEnter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node with key %d deleted.\n", key);
                break;
            case '3':
                inorder(root);
                break;
            case '4':
                preOrder(root);
                break;
            case '5':
                postOrder(root);
                break;
            case '6':
                printf("\nEnter the key to search: ");
                scanf("%d", &key);
                struct node *result = search(root, key);
                if (result != NULL) {
                    printf("Node with key %d found.\n", key);
                } else {
                    printf("Node with key %d not found.\n", key);
                }
                break;
            case '7':
                return 0;
            default:
                printf("Please Enter a Valid Choice.\n");
        }
    } while (1);
}
