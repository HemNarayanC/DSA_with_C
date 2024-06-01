
//Quick sort Implementation

#include <stdio.h>
#include <conio.h>

void quicksort(int arr[], int lb, int ub)
{
    int down = lb, up =ub, pivot = arr[lb], temp;
    while(down < up)       //if there are atleast 2 elements
    {
        while(down < ub && arr[down]<=pivot)        //increase down until larger element is found
        {
            down++;
        }

        while(arr[up]>pivot)        //decrease up until smaller or equal to pivot is found
        {
            up--;
        }

        if(down<up)     //if up and down are not met then exchange up and down elements
        {
            temp = arr[down];
            arr[down] = arr[up];
            arr[up] = temp;
        }

        else        //already crossed/met then exchange up with pivot element and repeat the same 
        {
            temp = arr[lb];
            arr[lb] = arr[up];
            arr[up] = temp;
            quicksort(arr, lb, up-1);       //sort the list of smal ler elements using quick sort
            quicksort(arr,up+1, ub);        //sort the list of bigger elements using quick sort
        } 
    }
}

void main()
{
    int arr[]={12, 4, 5, 2, 7, 9, 11, 10, 6, 3};
    int i, n=sizeof(arr)/sizeof(int);
    printf("Before Sorting: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    quicksort(arr, 0, n-1);

    printf("\nAfter Sorting: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }

    getch();
}

