#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int lb, int ub){
    // if(lb<ub){
    int pivot = arr[lb];
    int start = lb, end = ub;
    int temp;
    while(start<end){
        while(start<end && arr[start]<=pivot){
            start++;
        }

        while(arr[end]>pivot){
            end--;
        }

        if(start<end){
            temp = arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    quickSort(arr, lb, end-1);
    quickSort(arr, end + 1, ub);
}
// }

int main(){
    int arr[]={20, 25, 6, 3, 8, 19, 75, 44, 0, 36, 13, 88, 21, 12, 35};
    int length = sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Before Sorting: \n");
    for(i = 0; i < length; i++){
        printf("%d\t", arr[i]);
    }

    quickSort(arr, 0, length-1);

    printf("\nAfter Sorting: \n");
    for(i=0; i<length; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}