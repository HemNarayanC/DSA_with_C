
/*
    PostFix Expression: 753*51$/+32-+
    ________ _______ _______ _______ _______ _______ _______ _______ _______ _______
    |       |       |       |       |       |       |       |       |       |       |
    |       |       |   1   |       |       |       |       |       |       |       |
    |_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|
    |       |       |       |       |       |       |       |       |       |       |
    |   3   |   5   |   5   |   5   |       |       |       |   2   |       |       |      
    |_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|
    |       |       |       |       |       |       |       |       |       |       |
    |   5   |  15   |  15   |  15   |  3    |       |   3   |   3   |   1   |       |
    |_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|
    |       |       |       |       |       |       |       |       |       |       |
    |   7   |   7   |   7   |   7   |   7   |  10   |  10   |  10   |  10   |  11   |
    |_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|
    |       |       |       |       |       |       |       |       |       |       |
    |   *   |   5   |   1   |   $   |   /   |   +   |   3   |   2   |   -   |   +   |           scanning the characters
    |_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|                           
    
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int operandStack[MAX];
char prefix[MAX];
int top=-1;

void push(int);
int pop();
int post_eval();

int main()
{
    int result;
    printf("Enter the infix expression: ");
    gets(prefix);

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
    for(i=strlen(prefix)-1; i>=0; i--)
    {
        if(prefix[i]>='0' && prefix[i]<='9')
        {
            push(prefix[i]-'0');
        }

        else
        {
            //pop the topmost element
            operand1=pop();
            operand2=pop();

            switch(prefix[i])
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