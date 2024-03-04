#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int top=-1;
char infix[MAX];
char opstack[MAX], postfix[MAX];

int isFull()
{
    if (top==MAX-1)
    {
        /* code */
        return 1;
    }

    else
    {
        return 0;
    } 
}

int isEmpty()
{
    if (top==-1)
    {
        /* code */
        return 1;
    }

    else
    {
        return 0;
    }
    
}

void push(char ch)
{
    if(isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top=top+1;
    opstack[top]=ch;
}

char pop()
{
    char ch;
    if (isEmpty())
    {
        /* code */
        printf("Stack underflow\n");
        exit(1);
    }
    ch=opstack[top];
    top=top-1;
    return ch;
}

int getPrecedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;

    case '+':
    case '-':
        return 1;
    
    default:
        return 0;
    }
}

void print()
{
    int i;
    printf("Equivalent postfix: ");
    for(i=0; postfix[i]!='\0'; i++)
    {
        printf("%c", postfix[i]);
    }
}

void intoPostfix()
{
    int i, j=0;
    char symbol, next;

    for(i=0; infix[i]!='\0'; i++)
    {
        symbol=infix[i];
        
        if(symbol=='(')
        {
            push(symbol);
        }

        else if(symbol==')')
        {
            while((next=pop())!='(')
            {
                postfix[j++]=next;
            }
        }

        else if (symbol=='^' || symbol=='/' ||
                 symbol=='*' || symbol=='+' ||
                 symbol=='-')
        {
            /* code */
            while(!isEmpty() && getPrecedence(opstack[top])>=getPrecedence(symbol))
            {
                postfix[j++]=pop();
            }
            push(symbol);
        }

        else
        {
            postfix[j++]=symbol;
        }   
    }

    while (!isEmpty())
    {
        /* code */
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int main()
{
    printf("Enter the Infix expression: ");
    gets(infix);

    intoPostfix();

    print();

    return 0;    
}



