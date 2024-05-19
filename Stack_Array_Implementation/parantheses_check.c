#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack *s, char ch);
char pop(struct Stack *s);
int isEmpty(struct Stack *s);

// Main function to check balance
int checkBalance(char *expression) {
    struct Stack s;
    s.top = -1;
    int i;

    // Traverse the expression
    for (i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If the character is an opening parenthesis, push it onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        }
        // If the character is a closing parenthesis, check if it matches the top of the stack
        else if (ch == ')' || ch == ']' || ch == '}') {
            // If the stack is empty or the top does not match the current closing parenthesis, return 0 (unbalanced)
            if (isEmpty(&s) || ((ch == ')' && pop(&s) != '(') || (ch == ']' && pop(&s) != '[') || (ch == '}' && pop(&s) != '{'))) {
                return 0;
            }
        }
    }

    // If the stack is empty after traversing the expression, it's balanced
    return isEmpty(&s);
}

// Function to push an item onto the stack
void push(struct Stack *s, char ch) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = ch;
}

// Function to pop an item from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Main function
int main() {
    char expression[MAX_SIZE];
    
    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    // Check balance and print result
    if (checkBalance(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}

