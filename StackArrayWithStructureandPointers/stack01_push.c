
//WAP to push the data into the stack, display them and exit the program

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    /* data */
    int top;
    int arr[MAX];
}stack;

void push(stack *ptr, int num)
{
    if(ptr->top==MAX-1)
    {
        printf("Stack is full.\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top]=num;
}

void display(stack *ptr)
{
    int i;
    if(ptr->top==-1)
    {
        printf("Stack is empty.\n");
        return;
    }
    for(i=ptr->top; i>=0; i--)
        printf("%d\n", ptr->arr[i]); 
}

int main()
{
    int choice, data;
    stack s;
    s.top=-1;
   
    while(1)
    {
         printf("\n1.Push\n2.Display\n3.Exit\n");
         printf("Enter your choice:");
         scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&s, data);
                break;

            case 2:
                display(&s);
                break;

            case 3:
                exit(1);
                break;

            default:
                printf("Wrong Choice!");
        }
    }
    return 0;
}