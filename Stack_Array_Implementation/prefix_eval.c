#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int operandStack[MAX];
char postfix[MAX];
int top=-1;

void push(int);
int pop();
int post_eval();

int main()
{
    int result;
    printf("Enter the prefix expression: ");
    gets(postfix);

    result=post_eval();
    printf("The result obtained after the postfix evaluation is: %d", result);
}

void push(int value)
{
    if(top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }

    operandStack[++top]=value;
}

int pop()
{
    int val;
    if(top==-1)
    {
        printf("Stack underflow\n");
        exit(1);
    }    

    return val=operandStack[top--];
}

int post_eval()
{
    int i;
    int operand1, operand2;
    for(i=strlen(postfix)-1; i>=0; i--)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }

        else
        {
            //pop the topmost element
            operand1=pop();
            operand2=pop();

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