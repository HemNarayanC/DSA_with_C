
//WAP to implement Queue using Array

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5

struct queue{
    int front, rear;
    int queueArr[MAX];
};

// Function to check if the queue is full
int isFull(struct queue *ptr)
{
    if(ptr->rear==MAX-1)
        return 1;
    else
        return 0;
}

//Function to check if the queue is empty
int isEmpty(struct queue *ptr)
{
    if(ptr->front==-1 || ptr->front > ptr->rear)        /* If front pointer is at -1 or front exceeds rear, Queue is empty;  when we keep dequing
                                                            the item front index gets increased */
        return 1;
    else
        return 0;
}

//Function to insert elements into the array of Queue
void enqueue(struct queue *q, int a)
{
    if(isFull(q))
    {
        printf("\nQueue overflow.\n");
        return;
    }

    else 
    {
        if(q->front==-1)
            q->front=0;
        
        q->queueArr[++(q->rear)]=a;
        printf("Item is enqueued successfully.\n");
    }
}

//Function to dequeue the elements
int dequeue(struct queue *q)
{
    int data;
    if(isEmpty(q))
    {
        printf("Queue underflow.\n");
        exit(1);
    }

    data = q->queueArr[q->front++];
    printf("FrontIndex=%d\n", q->front);        //display the front index after each element is dequeued.
    return data;
}


//Function to display all the items in the queue
void display(struct queue *ptr)
{
    int i;
    if(isEmpty(ptr))
    {
        printf("Queue underflow.\n");
        return;
    }
    printf("Items in the queue are: \n");
    for(i=ptr->front; i<=ptr->rear; i++)
    {
        printf("%d\t", ptr->queueArr[i]);
    }
}

//Function to show the front element of the queue.
void frontElement(struct queue *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow.\n");
        return;
    }

    printf("Front Item is %d\n", ptr->queueArr[ptr->front]);
}

void rearIndex(struct queue *ptr)
{
    printf("Rear is at Index %d\n", ptr->rear);     //keep the track of the rear index
}

int main()
{
    int data;
    char ch;
    struct queue q;
    q.front = q.rear = -1;
    while(1)
    {
        printf("\nEnter the option:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front\n5.RearIndex\n6.Exit\n");
        ch = getch();
        switch(ch)
        {
            case '1':
                printf("Enter the item to be Enqueued: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;

            case '2':
                data = dequeue(&q);
                printf("Dequeued data is %d\n", data);
                break;

            case '3':
                display(&q);
                break;
            
            case '4':
                frontElement(&q);
                break;

            case '5':
                rearIndex(&q);
                break;
            
            case '6':
                exit(0);
                break;

            default:
                printf("Invalid Choice.");
        }
    }
}
