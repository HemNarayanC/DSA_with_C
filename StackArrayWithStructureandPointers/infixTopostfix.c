
//WAP to convert the infix expression into the postfix expression

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

struct stackInfix{
    int top;
    char infix[MAX], postfix[MAX], stackChar[MAX];
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
            break;
        
        case '/':
        case '*':
            return 2;
            break;

        case '+':
        case '-':
            return 1;
            break;
        
        default:
            return 0;
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
                
            case ')':            // Pop operators from the stack and append to the postfix expression until '(' is encountered
                    while((next=pop(s))!='(')
                        s->postfix[j++]=next;
                        break;
            case '$':
            case '/':
            case '+':
            case '*':
            case '-':
                 // Pop operators with higher precedence from the stack and append to the postfix expression
                    while(!isEmpty(s) && getPrecedence(s->stackChar[s->top]) > getPrecedence(symbol))
                        s->postfix[j++]=s->stackChar[s->top];
                    push(s, symbol);
                    break;
            
            default:
                s->postfix[j++]= symbol;
        }
    }
    // Pop any remaining operators from the stack and append to the postfix expression
    while(!isEmpty(s))
        s->postfix[j++]=pop(s);
    s->postfix[j++]='\0';
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
}

int main()
{
    struct stackInfix s;
    s.top=-1;
    printf("Enter the infix expression: ");
    fgets(s.infix, MAX, stdin);
    intoPost(&s);
    displayPostfix(&s);
    return 0;
}

