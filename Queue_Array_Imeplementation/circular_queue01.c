// WAP to implement the circular queue using array

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

// Structure to represent a circular queue
struct queue{
    int front, rear;
    int queueArr[MAX];
};

void enqueue(struct queue *q, int data)
{
    if((q->rear+1)%MAX==q->front)           // Check if the queue is full
    {
        printf("Queue overflow.\n");
        return;
    }

    else
    {
        if(q->front==-1)            // If queue is empty, set front to 0
            q->front=0;
        q->queueArr[(q->rear=((q->rear+1)%MAX))]=data;
        printf("Item Enqueued Successfully.\n");
    }
}

int dequeue(struct queue *q)
{
    int data; 
    if(q->front==-1)
    {
        printf("Queue underflow.\n");
        exit(1);
    }

    else if(q->front==q->rear)          // If only one element is present in the queue then set rear and front to -1
    {
        data=q->queueArr[q->front];
        q->front=q->rear=-1;
        return data;
    }

    else
    {
        data = q->queueArr[q->front];
        q->front=(q->front+1)%MAX;
        return data;
    }
}

void display(struct queue *ptr)
{
    int i;
    if(ptr->front==-1)
    {
        printf("Queue underflow.\n");
        return;
    }
    printf("Items in a Queue:\n");
    for(i=ptr->front; i!=ptr->rear; i=(i+1)%MAX)
    {
        printf("%d\t", ptr->queueArr[i]);           // Display elements from front to rear      
    }
    printf("%d\t", ptr->queueArr[i]);           // Display the last element
}

// Function to display the front element of the circular queue
void frontElement(struct queue *ptr)
{
    if(ptr->front==-1)
    {
        printf("Queue underflow.\n");
        return;
    }

    printf("Item at Front = %d\n", ptr->queueArr[ptr->front]);
}

void rearIndex(struct queue *q)         // Function to display the index of the rear pointer in the circular queue
{
    printf("Rear is at Index %d\n", q->rear);
}

void frontIndex(struct queue *q)        // Function to display the index of the front pointer in the circular queue
{
    printf("Front is at Index %d\n", q->front);
}

int main()
{
    int data;
    char choice;
    struct queue q;
    q.front = q.rear = -1;

    while(1)
    {
        printf("\nEnter the option:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front\n5.RearIndex\n6.FrontIndex\n7.Exit\n");
        choice = getch();
        switch(choice)
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
                frontIndex(&q);
                break; 
            
            case '7':
                exit(0);
                break;

            default:
                printf("Invalid Choice.");
        }
    }
    return 0;
}