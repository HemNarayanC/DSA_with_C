#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int pri_que[MAX];
    int front, rear;
} PriorityQueue;

void insert_by_priority(PriorityQueue *, int);
void delete_by_priority(PriorityQueue *queue);
void create(PriorityQueue *);
void display_pqueue(PriorityQueue *);

void main() {
    PriorityQueue queue;
    create(&queue);

    int n, ch;

    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter value to be inserted : ");
                scanf("%d", &n);
                insert_by_priority(&queue, n);
                break;
            case 2:
                // printf("\nEnter value to delete : ");
                // scanf("%d", &n);
                delete_by_priority(&queue);
                break;
            case 3:
                display_pqueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}

void create(PriorityQueue *queue) {
    queue->front = queue->rear = -1;
}

void insert_by_priority(PriorityQueue *queue, int data) {
    if (queue->rear >= MAX - 1) {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((queue->front == -1) && (queue->rear == -1)) {
        queue->front++;
        queue->rear++;
        queue->pri_que[queue->rear] = data;
        return;
    }
 
    int i;
    for (i = queue->rear; i >= 0; i--) {
        if (data > queue->pri_que[i])
            queue->pri_que[i + 1] = queue->pri_que[i];
        else
            break;
    }
 
    queue->pri_que[i + 1] = data;
    queue->rear++;
}

// void delete_by_priority(PriorityQueue *queue, int data) {
//     if ((queue->front == -1) && (queue->rear == -1)) {
//         printf("\nQueue is empty, no elements to delete");
//         return;
//     }

//     int i, found = 0;
//     for (i = 0; i <= queue->rear; i++) {
//         if (data == queue->pri_que[i]) {
//             found = 1;
//             break;
//         }
//     }

//     if (found) {
//         for (; i < queue->rear; i++)
//             queue->pri_que[i] = queue->pri_que[i + 1];

//         queue->rear--;
//         printf("\nDeleted element: %d", data);

//         if (queue->front > queue->rear)
//             queue->front = queue->rear = -1;
//     } else {
//         printf("\n%d not found in queue to delete", data);
//     }
// }

void delete_by_priority(PriorityQueue *queue) {
    if ((queue->front == -1) && (queue->rear == -1)) {
        printf("\nQueue is empty, no elements to delete");
        return;
    }

    int deleted_element = queue->pri_que[queue->front];
    queue->front++;

    printf("\nDeleted element: %d", deleted_element);

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1; // Reset the queue
    }
} 



void display_pqueue(PriorityQueue *queue) {
    if ((queue->front == -1) && (queue->rear == -1)) {
        printf("\nQueue is empty");
        return;
    }

    printf("\nQueue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->pri_que[i]);
    }
}
