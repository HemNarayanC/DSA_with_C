#include <stdio.h>
#include <stdlib.h>

// Function prototypes for sorting algorithms
void bubbleSort(int arr[], int n);
void countSort(int arr[], int n);
void heapSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void shellSort(int arr[], int n);
void radixSort(int arr[], int n);

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Function to perform sorting based on user input
void performSorting(int arr[], int n, int choice) {
    switch (choice) {
        case 1:
            printf("Bubble Sort:\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Count Sort:\n");
            countSort(arr, n);
            break;
        case 3:
            printf("Heap Sort:\n");
            heapSort(arr, n);
            break;
        case 4:
            printf("Insertion Sort:\n");
            insertionSort(arr, n);
            break;
        case 5:
            printf("Selection Sort:\n");
            selectionSort(arr, n);
            break;
        case 6:
            printf("Shell Sort:\n");
            shellSort(arr, n);
            break;
        case 7:
            printf("Radix Sort:\n");
            radixSort(arr, n);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("After sorting:\n");
    printArray(arr, n);
}

int main() {
    int arr[] = {13, 21, 5, 62, 12, 6, 7, 23, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    printf("Original Array:\n");
    printArray(arr, n);

    printf("Choose a sorting technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Count Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Insertion Sort\n");
    printf("5. Selection Sort\n");
    printf("6. Shell Sort\n");
    printf("7. Radix Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    performSorting(arr, n, choice);

    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Count Sort
#define MAXVALUE 100 // Adjust maximum value as per your input constraints

void countSort(int arr[], int n) {
    int count[MAXVALUE + 1] = {0}; // Assuming maximum value of arr elements is MAXVALUE
    int output[n];
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= MAXVALUE; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSortRadix(int arr[], int n, int exp) {
    int output[n]; 
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}
