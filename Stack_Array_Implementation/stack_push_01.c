/*Stack with array implementation*/

#include <stdio.h>
#define MAX 4
#define MORE 5

void push(int);
void pop();

int stack_arr[MAX];
int top=-1;

int main()
{
    int i, num, data;

    for(i=0; i<MORE; i++)
    {
        printf("Enter the element to be pushed: ");
        scanf("%d", &num);
        push(num);
    }
    // push(1);
    // push(2);
    // push(3);
    // push(4);
    // push(5);

    // for(i=0; i<MORE; i++)
    // {
    //     data=pop();
    // }
    // return 0;
}

void push(int data)
{
    if(top==MAX-1)
    {
        printf("Stack overflow\n");
        return; 
    }
        top=top+1;
        stack_arr[top]=data;
        printf("Successfully pushed\n");
}

// void pop()
// {
//     int value;
    
//     if(top==-1)
//     {
//         printf("Stack underflow.\n");
//         exit(1);
//     }
//     value=stack_arr[top];
//     top=top-1;
//     return value;
// }