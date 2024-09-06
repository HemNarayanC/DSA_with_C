
//stack implementation using array in c

#include <stdio.h>
#include <conio.h>
// #include <string.h>
#include <stdlib.h>
#define MAX 5

struct stack{
    int top;            //top of the stack
    int stackArr[MAX];          //Array to store the stack elements
};

int isFull(struct stack *ptr)       //function to check if the stack is full
{
    if(ptr->top==MAX-1)
        return 1;       //stack is full
    else
        return 0;       //stack is not full
}

int isEmpty(struct stack *ptr)      //function to check if the stack is empty
{
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int num)       //function to push element onto the stack
{
    if(isFull(ptr))
    {
        printf("Stack overflow.\n");
        return;
    }
    ptr->stackArr[++(ptr->top)]=num;
    printf("Item pushed successfully.\n");          //display success meassage
}

int pop(struct stack *p)            //function to pop an element out of the stack
{
    int data;
    if(isEmpty(p))
    {
        printf("Stack underflow.\n");
        exit(1);
    }
    data = p->stackArr[p->top--];
    return data;
}

void display(struct stack *s)           //function to display all the items of the stack
{
    int i;
    if(isEmpty(s))
    {
        printf("No items to display.\n");
        exit(0);
    }
    printf("\nItems in the stack:\n");
    for(i=s->top; i>=0; i--)
        printf("%d\n", s->stackArr[i]);
}

void peek(struct stack *s)              //function to display the topmost element of the stack
{
    if(isEmpty(s))
    {
        printf("Stack underflow.\n");
        return;
    }

    printf("Item at top = %d\n", s->stackArr[s->top]);
}


int main()
{
    int data;
    char choice;

    struct stack s;
    s.top=-1;

    printf("\nEnter your choice:\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");

    while(1)
    {
        choice=getch();
        switch(choice)
        {
            case '1':           //push operation
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&s, data);
                break;

            case '2':       //pop operation
                data=pop(&s);
                printf("Popped item is:%d\n", data);
                break;

            case '3':           //display all items in the stack
                display(&s);
                break;
            
            case '4':           //display topmost item
                peek(&s);
                break;
            
            case '5':           //exit the program
                exit(1);
                break;
            
            default:
                printf("Invalid Choice!\n");
        }

    }
    return 0;
}