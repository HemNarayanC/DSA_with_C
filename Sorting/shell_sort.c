//shell sort implementation

#include <stdio.h>
#include <conio.h>

void shellSort(int arr[], int n)
{
    int i, j, temp, gap;

    for(gap=n/2; gap>0; gap=gap/2)
    {
        for(i=gap; i<n; i++)
        {
            temp = arr[i];      //the item to be inserted is temporarily kept in temp
            for(j=i-gap; j>=0 && arr[j]>temp; j=j-gap)
                arr[j+gap]=arr[j];
            arr[j+gap] = temp;      //insert the item into sorted list
        }
    }
}

void main()
{
    int arr[] = {15, 12, 4, 11, 6, 7, 9, 4, 5, 2};
    int i, n = sizeof(arr)/sizeof(int);
    printf("Before Sorting: \n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    shellSort(arr, n);
    printf("\nAfter Sorting: \n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    getch();
}