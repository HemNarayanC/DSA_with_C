#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

struct queue //version 1
{
    int front;
    int rear;
    int items[MAX];
};

int isEmpty(struct queue *q)
{
    if(q->rear < q->front)
        return TRUE;
    
    else
        return FALSE;
}

int isFull(struct queue *q)
{
    if(q->rear==MAX-1)
        return TRUE;
    else
        return FALSE;
}

void enqueue(struct queue *q, int n)
{
    if(isFull(q))
    {
        printf("Queue is Full");
        getch();
        return;
    }

    q->rear++;
    q->items[q->rear]=n;;
    printf("\nItem inserted into the queue");
}

void dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("\nQueue is Empty.");
        getch();
        return;
    }

    q->front++;
    printf("\nItem removed from the queue.");
}

void display(struct queue *q)
{
    int i;
    if(isEmpty(q))
        printf("\nQueue is Empty.");
    else
    {
        printf("\nQueue contains: \n");
        for(i=q->front; i<=q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}

void main()
{
    struct queue q;
    char ch;
    int n;
    q.front=0;
    q.rear=-1;
    do
    {
        /* code */
        printf("\nEnter your option:\n");
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        fflush(stdin);
        ch=getche();
        switch(ch)
        {
            case '1':
                printf("\nEnter a number: ");
                scanf("%d", &n);
                enqueue(&q, n);
                break;
            
            case '2':
                dequeue(&q);
                break;
            
            case '3':
                display(&q);
                break;
            
            case '4':
                return;
        }
        getch();
    } while (/* condition */TRUE);
    
}

