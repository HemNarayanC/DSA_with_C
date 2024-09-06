#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct stackInfix{
    int top;
    char infix[MAX], postfix[MAX];
    char stackChar[MAX];        //array to store the operators
};

int isFull(struct stackInfix *ptr)
{
    if(ptr->top==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stackInfix *ptr)
{
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

void push(struct stackInfix *ptr, char ch)
{
    if(isFull(ptr))
    {
        printf("Stack overflow.\n");
        return;
    }

    ptr->stackChar[++(ptr->top)]=ch;
}

char pop(struct stackInfix *q)
{
    char ch;
    if(isEmpty(q))
    {
        printf("Stack underflow.\n");
        exit(0);
    }
    ch=q->stackChar[q->top--];
    return ch;
}

int getPrecedence(char ch)
{
    switch(ch)
    {
        case '$':
            return 3;
        
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

int getAssociativity(char ch)
{
    switch(ch)
    {
        case '$':
            return 1;  // Right associative
        case '/':
        case '*':
        case '+':
        case '-':
            return 0;  // Left associative
        default:
            return -1; // Not an operator
    }
}

// Function to convert infix expression to postfix expression
void intoPost(struct stackInfix *s)
{
    int i, j=0;
    char next, symbol;
    for(i=0; i<strlen(s->infix); i++)
    {
        symbol=s->infix[i];
        switch(symbol)
        {
            case '(':
                push(s, symbol);
                break;
                
            case ')':  // Pop operators from the stack and append to the postfix expression until '(' is encountered
                while((next=pop(s))!='(')
                    s->postfix[j++]=next;
                break;

            case '$':
            case '/':
            case '+':
            case '*':
            case '-':
                // Pop operators with higher or equal precedence from the stack and append to the postfix expression
                while(!isEmpty(s) && getPrecedence(s->stackChar[s->top]) >= getPrecedence(symbol) && getAssociativity(symbol) == 0)
                    s->postfix[j++]=pop(s);
                push(s, symbol);
                break;
            
            default:    //If it's operand then directly push into the poststack
                s->postfix[j++]= symbol;
        }
    }
    // Pop any remaining operators from the Operator stack and append to the postfix expression
    // suitable example for this is A+B*(C-D/E)
    while(!isEmpty(s))
        s->postfix[j++]=pop(s);
    s->postfix[j]='\0';
}

// Function to display the postfix expression
void displayPostfix(struct stackInfix *p)
{
    int i;
    printf("Equivalent Postfix Expression: ");
    for(i=0; p->postfix[i]!='\0'; i++ )
    {
        printf("%c", p->postfix[i]);
    }
    printf("\n");
}

int main()
{
    struct stackInfix s;
    s.top=-1;
    printf("Enter the infix expression: ");
    fgets(s.infix, MAX, stdin);
    s.infix[strcspn(s.infix, "\n")] = '\0';  // Remove newline character
    intoPost(&s);
    displayPostfix(&s);
    return 0;
}
