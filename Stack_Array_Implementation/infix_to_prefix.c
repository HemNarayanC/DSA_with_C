#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c=='$') {
        return 1;
    }
    return 0;
}

int precedence(char c) {
    if(c=='$')
        return 3;
    else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

int isOperand(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
        return 1;
    }
    return 0;
}

void infixToPrefix(char infix[]) {
    char prefix[MAX_SIZE];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isOperand(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                prefix[j++] = pop();
            }
            pop();
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    
    printf("Prefix expression: %s\n", prefix);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix);

    return 0;
}