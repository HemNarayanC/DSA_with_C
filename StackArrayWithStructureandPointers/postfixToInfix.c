#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    char infixStack[MAX][MAX];  // Array of strings to act as stack
    int top;                    // Top of the stack
    char postfix[MAX];          // Postfix expression to be converted
} stack;

void push(stack *s, char expression[]);
char* pop(stack *s);
void postToinfix(stack *s);

int main() {
    stack s;
    s.top = -1;

    printf("Enter the postfix expression: ");
    fgets(s.postfix, MAX, stdin);
    s.postfix[strcspn(s.postfix, "\n")] = '\0'; // Remove newline character

    postToinfix(&s);
    return 0;
}

void push(stack *s, char expression[]) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(s->infixStack[++(s->top)], expression);
}

char* pop(stack *s) {
    static char expression[MAX];
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(0);
    }
    return strcpy(expression, s->infixStack[(s->top)--]);
}

void postToinfix(stack *s) {
    int i;
    char inchar[2] = {'\0'};    // To accept individual character from the postfix 
    char lt[2] = {'(', '\0'}, rt[2] = {')', '\0'}; // Left and right parentheses
    char exp[MAX] = {'\0'};    // To store the new expression along with the operator
    char exp1[MAX], exp2[MAX];    // To store the two popped expressions/characters after encountering the operator

    for (i = 0; s->postfix[i] != '\0'; i++) {
        inchar[0] = s->postfix[i];
        inchar[1] = '\0';

        if (isalnum(s->postfix[i])) {
            // If the character is a letter or digit, push it onto the stack
            push(s, inchar);
        } else if (s->postfix[i] == '$' || s->postfix[i] == '/' || s->postfix[i] == '*' || s->postfix[i] == '+' || s->postfix[i] == '-') {
            // If the character is an operator
            strcpy(exp2, pop(s));    // Store the topmost popped expression into exp2
            strcpy(exp1, pop(s));    // Store the next popped expression into exp1
            strcat(exp, lt);    // Concatenate the left parenthesis
            strcat(exp, exp1);  // Concatenate the first operand
            strcat(exp, inchar);    // Concatenate the operator
            strcat(exp, exp2);  // Concatenate the second operand
            strcat(exp, rt);    // Concatenate the right parenthesis
            push(s, exp);  // Push the new expression onto the stack
        } else {
            printf("Invalid Arithmetic Expression.\n");    // If the character is none of the above, print error and exit
            exit(0);
        }

        memset(exp, '\0', sizeof(char) * MAX);    // Reset exp array to store the next new expression
    }

    printf("Equivalent Infix Expression is %s\n", s->infixStack[s->top]);
}
