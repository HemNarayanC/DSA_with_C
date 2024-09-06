//Implementation of Binary Search using iterative method

#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int lb, int ub, int key)
{
    int mid;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;      //compute mid position
        if(key==arr[mid])       //compare key with mid
            return mid;     //if equal return mid value
        else if(arr[mid]>key)       //if key is not equal to mid then check if mid value i
            ub=mid-1;
        else        //if search item is greater than mid item then search in the second half
            lb=mid+1;
    }
   return -1;
}

void main()
{
    int arr[]={2,11,15,20,38,40,55,101,115,122};
    int i, key, n=sizeof(arr)/sizeof(int);
    printf("Enter a number you want to search:");
    scanf("%d", &key);
    i=binarySearch(arr, 0, n-1, key);
    if(i==-1)       //if item does not exist in the list
        printf("%d not found.", key);
    else
        printf("%d found at position %d", key, i+1);
    getch();
}