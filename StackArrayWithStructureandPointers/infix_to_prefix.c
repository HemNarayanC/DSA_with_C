#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

struct stack{
    int top;
    char opstack[MAX];
	char prefix[MAX];
};

int isFull(struct stack *ptr)
{
    if (ptr->top==MAX-1)
    {
        /* code */
        return 1;
    }

    else
    {
        return 0;
    } 
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top==-1)
    {
        /* code */
        return 1;
    }

    else
    {
        return 0;
    }
    
}

void push(struct stack *ptr, int ch)
{
    if(isFull(ptr))
    {
        printf("Stack overflow\n");
        return;
    }
    ptr->opstack[++(ptr->top)]=ch;
}

int pop(struct stack *ptr)
{
    char ch;
    if (isEmpty(ptr))
    {
        /* code */
        printf("Stack underflow\n");
        exit(1);
    }
    ch=ptr->opstack[ptr->top];
    ptr->top--;
    return ch;
}

int getPrecedence(char symbol)
{
    switch (symbol)
    {
    case '$':
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

void intoPrefix(struct stack *s, char *infix)
{
    int i, j=0;
    char symbol, next;

    for(i=strlen(infix)-1; i>=0; i--)
    {
        symbol=infix[i];
        
        if(symbol==')')
        {
            push(s, symbol);
        }

        else if(symbol=='(')
        {
            while((next=pop(s))!=')')
            {
                s->prefix[j++]=next;
            }
        }

        else if (symbol=='$' || symbol=='/' ||
                 symbol=='*' || symbol=='+' ||
                 symbol=='-')
        {
            /* code */
            while(!isEmpty(s) && getPrecedence(s->opstack[s->top])>=getPrecedence(symbol))
            {
                s->prefix[j++]=pop(s);
            }
            push(s, symbol);
        }

        else
        {
            s->prefix[j++]=symbol;      //if the symbol is an operand
        }   
    }

    while (!isEmpty(s))
    {
        /* code */
        s->prefix[j++]=pop(s);
    }
    s->prefix[j]='\0';
} 

void print(struct stack *s)
{
    int i;
    printf("Equivalent prefix: ");
    for(i=strlen(s->prefix)-1; i>=0; i--)
    {
        printf("%c", s->prefix[i]);
    }
    printf("\n");
}

int main()
{
	char infix[MAX];
	struct stack s;
	s.top=-1;
    printf("Enter the Infix expression: ");
    gets(infix);

    intoPrefix(&s, infix);
    print(&s);
    return 0;    
}