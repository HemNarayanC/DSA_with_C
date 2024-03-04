#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 50

typedef struct 
{
    /* data */
    char infixStack[MAX];
} stack;

stack s[MAX];
int top = -1;
char postfix[MAX];

void push(char []);
char* pop();
void postToinfix();

int main()
{
    printf("Enter the postfix expression: ");
    gets(postfix);

    postToinfix();
    return 0;
}

void push(char expression[])
{
    if(top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    strcpy(s[++top].infixStack, expression);
}

char* pop()
{
    char expression[MAX];
    if(top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }

    return strcpy(expression, s[top--].infixStack);
}

void postToinfix()
{
    int i;
    char inchar[2]={'\0'};    // To accept individual character from the postfix 
    char lt[2]={'(', '\0'}, rt[2]={')', '\0'}; // Left and right parentheses
    char exp[MAX]={'\0'};    // To store the new expression along with the operator
    char exp1[MAX], exp2[MAX];    // To store the two popped expression/character after encountering the operator

    for(i = 0; postfix[i] != '\0'; i++)
    {
        inchar[0] = postfix[i];
        inchar[1] = '\0';

        if((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= '0' && postfix[i] <= '9'))
        {
            // If the character is a letter or digit, push it onto the stack
            push(inchar);
        }
        else if(postfix[i] == '$' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-')
        {
            // If the character is an operator
            strcpy(exp2, pop());    // Store the topmost popped expression into exp2
            strcpy(exp1, pop());    // Store the next popped expression into exp1
            strcat(exp, lt);    // Concatenate the left parenthesis
            strcat(exp, exp1);  // Concatenate the first operand
            strcat(exp, inchar);    // Concatenate the operator
            strcat(exp, exp2);  // Concatenate the second operand
            strcat(exp, rt);    // Concatenate the right parenthesis
            push(exp);  // Push the new expression onto the stack
        }
        else
        {
            printf("Invalid Arithmetic Expression.\n");    // If the character is none of the above, print error and exit
            exit(0);
        }

        memset(exp, '\0', sizeof(char) * MAX);    // Reset exp array to store the next new expression
    }

    printf("Equivalent Infix Expression is ");
    printf("%s", s[top].infixStack);
}
