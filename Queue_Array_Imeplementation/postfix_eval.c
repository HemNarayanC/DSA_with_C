#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

struct Queue {
    int front, rear;
    int items[MAX];
};

typedef struct Queue Queue;

void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int post_eval(char *postfix);

int main() {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;

    char postfix[MAX];
    int result;

    printf("Enter the postfix expression: ");
    gets(postfix);

    result = post_eval(postfix);
    printf("The result obtained after the postfix evaluation is: %d", result);

    return 0;
}

void enqueue(Queue *q, int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue overflow\n");
        exit(1);
    }

    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    int item;

    if (q->front == -1) {
        printf("Queue underflow\n");
        exit(1);
    }

    item = q->items[q->front];
    q->front = (q->front + 1) % MAX;

    return item;
}

int post_eval(char *postfix) {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;

    int operand1, operand2;

    for (int i = 0; i < strlen(postfix); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            enqueue(&queue, postfix[i] - '0');
        } else {
            operand2 = dequeue(&queue);
            operand1 = dequeue(&queue);

            switch (postfix[i]) {
                case '$':
                    enqueue(&queue, pow(operand1, operand2));
                    break;
                case '/':
                    enqueue(&queue, operand1 / operand2);
                    break;
                case '*':
                    enqueue(&queue, operand1 * operand2);
                    break;
                case '+':
                    enqueue(&queue, operand1 + operand2);
                    break;
                case '-':
                    enqueue(&queue, operand1 - operand2);
                    break;
                default:
                    printf("Error in operator\n");
                    exit(1);
            }
        }
    }
    return dequeue(&queue);
}