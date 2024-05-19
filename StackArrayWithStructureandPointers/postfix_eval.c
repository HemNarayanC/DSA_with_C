#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

struct stack {
    int top;
    int operandStack[MAX];
};

typedef struct stack Stack;

void push(Stack *s, int value);
int pop(Stack *s);
int post_eval(char *postfix);

int main() {
    Stack operandStack;
    operandStack.top = -1;

    char postfix[MAX];
    int result;

    printf("Enter the postfix expression: ");
    gets(postfix);

    result = post_eval(postfix);
    printf("The result obtained after the postfix evaluation is: %d", result);

    return 0;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }

    s->operandStack[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }

    return s->operandStack[(s->top)--];
}

int post_eval(char *postfix) {
    Stack operandStack;
    operandStack.top = -1;

    int operand1, operand2;
    for (int i = 0; i < strlen(postfix); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(&operandStack, postfix[i] - '0');
        } else {
            operand2 = pop(&operandStack);
            operand1 = pop(&operandStack);

            switch (postfix[i]) {
                case '$':
                    push(&operandStack, pow(operand1, operand2));
                    break;
                case '/':
                    push(&operandStack, operand1 / operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                default:
                    printf("Error in operator\n");
                    exit(1);
            }
        }
    }
    return pop(&operandStack);
}
