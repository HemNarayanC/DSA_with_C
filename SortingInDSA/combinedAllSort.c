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

// Main function
int main() {
    int arr[] = {13, 21, 5, 62, 12, 6, 7, 23, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Sort and print using each sorting algorithm
    bubbleSort(arr, n);
    printf("After Bubble Sort:\n");
    printArray(arr, n);

    countSort(arr, n);
    printf("After Count Sort:\n");
    printArray(arr, n);

    heapSort(arr, n);
    printf("After Heap Sort:\n");
    printArray(arr, n);

    insertionSort(arr, n);
    printf("After Insertion Sort:\n");
    printArray(arr, n);

    selectionSort(arr, n);
    printf("After Selection Sort:\n");
    printArray(arr, n);

    shellSort(arr, n);
    printf("After Shell Sort:\n");
    printArray(arr, n);

    radixSort(arr, n);
    printf("After Radix Sort:\n");
    printArray(arr, n);

    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Count Sort
void countSort(int arr[], int n) {
    const int MAXVALUE = 100; // Adjust as needed based on input data

    // Initialize count array
    int count[MAXVALUE + 1];
    for (int i = 0; i <= MAXVALUE; i++) {
        count[i] = 0;
    }

    // Fill count array with frequencies
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update count array to store actual positions
    int index = 0;
    for (int i = 0; i <= MAXVALUE; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Radix Sort
void countSortRadix(int arr[], int n, int exp) {
    int output[n]; // Output array
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSortRadix(arr, n, exp);
    }
}
