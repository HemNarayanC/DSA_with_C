/*Stack with array implementation*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MORE 10

void push(int);
int pop();
void print();

int stack_arr[MAX];
int top=-1;

int main()
{
    int data;

    push(1);
    push(2);
    push(3);
    push(4);
    // push(5);
    data=pop();
    data=pop();
    // data=pop();
    // data=pop();
    // data=pop();
    print();
    return 0;
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
}

int pop()
{
    int value;
    
    if(top==-1)
    {
        printf("Stack underflow.\n");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}

// Function to print all elements of the stack
void print()
{
    int i;

    // Check if the stack is empty
    if(top == -1)
    {
        printf("Stack underflow.\n"); // If stack is empty, print error message
        return; // Exit the function
    }

    // Iterate over the elements of the stack from top to bottom
    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack_arr[i]); // Print each element of the stack
    }
}
  