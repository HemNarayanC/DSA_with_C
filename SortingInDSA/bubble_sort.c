#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void bubblesort(int [], int);
void main()
{
    int arr[]={13, 21, 5, 62, 12, 6, 7, 23, 8, 10};
    int i, n=sizeof(arr)/sizeof(int);
    printf("Before Sorting: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }

    bubblesort(arr, n);

    printf("\nAfter Sorting: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    getch();
}

void bubblesort(int arr[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
