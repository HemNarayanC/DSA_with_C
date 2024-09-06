#include <stdio.h>
#include <conio.h>

int getSmallestPosition(int arr[], int i, int j)
{
    int pos=i, k;      //let us assume that smallest element is in kth position
    for(k=i+1; k<=j; k++)
    {
        if(arr[k]<arr[pos])
        {
            pos=k;
        }
    }
    return pos;
}

void SelectionSort(int arr[], int n)
{
    int i, smallestPosition, temp;
    for(i=0; i<n-1; i++)
    {
        smallestPosition=getSmallestPosition(arr, i, n-1);
        temp=arr[i];
        arr[i]= arr[smallestPosition];
        arr[smallestPosition]=temp;
    }
}
void main()
 {
    int arr[]={5, 12, 6, 2, 7, 9, 10, 4};
    int i, n =sizeof(arr)/sizeof(int);
    printf("Before Seclection Sort: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }

    SelectionSort(arr, n);
    printf("\nAfter Sorting: \n");
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    getch();
}