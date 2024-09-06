// Count Sort Implementation

#include <stdio.h>
#include <conio.h>
#define SIZE 15
#define MAXVALUE 21

int getHighestNumber(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n)
{
    int count[MAXVALUE] = {0}; // create a count array with initial value of zero
    int temp[SIZE];
    int k = getHighestNumber(arr, n);
    int i;
    // perform frequency count of each number in the array
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // then calculate cumulative frequency
    for (i = 1; i <= k; i++)
        // count[i]=count[i]+count[i-1];
        count[i] += count[i - 1];

    // now sort the items and put into temp array
    for (i = n - 1; i >= 0; i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }

    // finally copy back the temp into 
    for (i = 0; i < n; i++)
    arr[i] = temp[i];
}

void main()
{
    int arr[] = {7, 5, 3, 11, 9, 20, 2, 7, 3, 7};
    int i, n = sizeof(arr) / sizeof(int);
    printf("Before Sorting: \n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    countSort(arr, n);
    printf("\nAfter Sorting: \n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    getch();
}