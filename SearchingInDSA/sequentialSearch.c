#include <stdio.h>

int linearsearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) { // Use equality comparison
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {3, 5, 6, 7,5, 0, 3, 576, 32, 54, 30};
    int n = sizeof(arr) / sizeof(int);
    int key;

    printf("Enter a number you want to search: ");
    scanf("%d", &key);

    int i = linearsearch(arr, n, key);

    if (i == -1) { // Use equality comparison
        printf("%d does not exist in the list\n", key);
    } else {
        printf("%d is found at index %d\n", key, i);
    }

    return 0;
}
