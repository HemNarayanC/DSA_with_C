#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    int *ptr=(int *)malloc(2*sizeof(int));
    for(i=0; i<2; i++)
    {
        printf("Enter a number: ");
        scanf("%d", ptr+i);
    }
    
    printf("Displaying Numbers:\n");
    for(i=0; i<2; i++)
    {
        printf("%d\n", *(ptr+i));
    }

    ptr=(int *)realloc(ptr,4*sizeof(int));
    for(i=2; i<4; i++)
    {
        printf("Enter a number: ");
        scanf("%d", ptr+i);
    }
    
    printf("Displaying Numbers:\n");
    for(i=0; i<4; i++)
    {
        printf("%d\n", *(ptr+i));
    }
    return 0;
}