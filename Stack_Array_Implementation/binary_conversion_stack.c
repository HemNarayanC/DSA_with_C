#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top=-1;
int binaryStack[MAX];

void push(int rem)
{
    if(top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }
    binaryStack[++top]=rem;
}

int pop()
{
    int binary;
    if(top==-1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return binary=binaryStack[top--];
}

int main()
{
    int num, i;
    printf("Enter any number: "); 
    scanf("%d", &num);

    while(num!=1)
    {
        push(num%2);
        num=num/2;
    }
    push(num);

    printf("Equivalent binary number is ");
    for(i=top; i>=0; i--)
        printf("%d", pop());

    return 0;
}