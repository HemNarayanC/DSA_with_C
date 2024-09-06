//Implementation of Binary Search using Recursive method

#include <stdio.h>
#include <conio.h>

int binarySearchRecursive(int arr[], int lb, int ub, int key)
{
    int mid;
    if(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            return binarySearchRecursive(arr, lb, mid-1, key);
        else
            return binarySearchRecursive(arr, mid+1, ub, key);
    }
    return -1;
}

void main()
{
    int arr[]={2,11,15,20,38,40,55,101,115,122};
    int i, key, n=sizeof(arr)/sizeof(int);
    printf("Enter a number you want to search: ");
    scanf("%d", &key);
    i=binarySearchRecursive(arr, 0, n-1, key);
    if(i==-1)       //if item does not exist in the list
        printf("%d not found.", key);
    else
        printf("%d found at position %d", key, i+1);
    getch();
}