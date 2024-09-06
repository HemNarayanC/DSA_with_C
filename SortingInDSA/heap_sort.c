//Heap Sort Implementation

#include <stdio.h>
#include <conio.h>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void heapify(int arr[], int n, int i)
{
    int left, right, max;
    left = i*2 + 1;     //index of the left child in an array
    right = i * 2 + 2;      //index of right child in an array
    max = i;        //initially assume that parent is bigger
    if(left<n && arr[max]<arr[left])        //if left child is bigger than parent
        max = left;     //make left child as max
    if(right<n && arr[max]<arr[right])      //if right child is bigger than parent or 
        max = right;        //make right child as max
    if(max!=i)      //if parent is not bigger thanits children then
    {
        swap(&arr[i], &arr[max]);       //exchange parent with max child
        heapify(arr, n, max);       //recursivley call heapify on child subtree
    }

}

void heapSort(int arr[], int n)
{
    int i;
    //first create a max heap of array
    for(i=n/2; i>=0; i--)       //lets do from the last internal node to root node one by one
    {
        heapify(arr, n, i);
    }
    for(i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);       //swap the value of root and last child
        heapify(arr, i, 0);     //heapify root node again once more
    }
}

void main()
{
    int arr[]={11, 15, 8, 33, 4, 2, 11, 45, 7, 9};
    int i, n=sizeof(arr)/sizeof(int);
    printf("Before Sorting:\n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    heapSort(arr, n);
    printf("\nAfter Sorting:\n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    getch();
}