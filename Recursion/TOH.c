#include <stdio.h>

// Function to move disks from source to destination using auxiliary
void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(numDisks - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", numDisks, source, destination);
    towerOfHanoi(numDisks - 1, auxiliary, source, destination);
}

// Main function for menu-driven Tower of Hanoi
int main() {
    int numDisks, choice;
    char source = 'A', auxiliary = 'B', destination = 'C';
    
    do {
        printf("\nMenu:\n");
        printf("1. Solve Tower of Hanoi\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of disks: ");
                scanf("%d", &numDisks);
                printf("The sequence of moves involved in the Tower of Hanoi are:\n");
                towerOfHanoi(numDisks, source, auxiliary, destination);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 2);
    
    return 0;
}
