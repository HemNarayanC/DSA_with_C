#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int top=-1, operandStack[MAX];
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

void push(int ch)
{
    if(isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top=top+1;
    opstack[top]=ch;
}

int pop()
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

void print()
{
    int i;
    printf("Equivalent postfix: ");
    for(i=0; postfix[i]!='\0'; i++)
    {
        printf("%c", postfix[i]);
    }
    printf("\n");
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

        else if (symbol=='$' || symbol=='/' ||
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

int post_eval()
{
    int i;
    int operand1, operand2;
    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }

        else
        {
            //pop the topmost element
            operand2=pop();
            operand1=pop();

            switch(postfix[i])
            {
                case '$':
                    push(pow(operand1, operand2));
                    break;
                
                case '/':
                    push(operand1/operand2);
                    break;

                case '*':
                    push(operand1*operand2);
                    break;

                case '+':
                    push(operand1+operand2);
                    break;
                
                case '-':
                    push(operand1-operand2);
                    break;

                default:
                    printf("Error in operator\n");
            }
        }
    }
    return pop();
}

int main()
{
    printf("Enter the Infix expression: ");
    gets(infix);

    intoPostfix();
    print();

    int result=post_eval();
    printf("The result obtained after the postfix evaluation is: %d\n", result);

    return 0;    
}