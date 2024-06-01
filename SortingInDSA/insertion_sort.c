//Insertion sort Implementation

#include <stdio.h>
#include <conio.h>
void insertionSort(int arr[], int i, int j)
{
    int k, key, p;
    for(k=i+1; k<=j; k++)       //insert all elements from i+1 to j that already sorted list
    {
        key = arr[k];   //insert item at kth position
        p=k-1;      //start from just one position left of key
        while(p>=0 && arr[p]>key)
        {
            arr[p+1] = arr[p];      //move to right position if it is larger than key
            p--;
        }
        arr[p+1] = key;     //insert key into its final position
    }
}

void main()
{
    int arr[]={40, 25, 9, 17, 2, 6, 22, 7, 11, 5};
    int n = sizeof(arr)/sizeof(int), i;
    printf("Before Sorting: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }

    insertionSort(arr, 0, n-1);     //sort elements between 0 and n-1
    printf("\nAfter Sorting: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    getch();
}