// array implementation of stack
#include <stdio.h>
#include <conio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
struct stack
{
    int tos; //top of the stack
    int items[MAX]; //array is used as storehouse of stack
};

int isEmpty(struct stack *s)
{
    if (s->tos==-1)
        return TRUE;
    else
        return FALSE;
}

int isFull(struct stack *s) //overflow test
{
    //return s->tos==MAX-1;
    if (s->tos==MAX-1)
        return TRUE;
    else
        return FALSE;
}

int push(struct stack *s, int num)
{
    if(isFull(s))   //if stack is full then don't push
        return FALSE;//return FALSE to indicate that push has failed
    else
    {
        s->tos++;
        s->items[s->tos]=num;
        return TRUE; //return TRUE indicating the success of push
    }
}

int pop(struct stack *s)
{
    if(isEmpty(s))  //stack underflow
        return FALSE; //pop failed
    else{
        s->tos--;
        return TRUE; //pop success 
    }
}

int peek(struct stack *s)
{
    return s->items[s->tos];
}

void display(struct stack *s)
{
    int i;
    if(isEmpty(s))
        printf("\nStack is empty.");
    else
        printf("\nStack contains:\n");
        for(i=s->tos; i>=0; i--)
        {
            printf("%d\n", s->items[i]);
        }
}

int main()
{
    struct stack s;
    char choice;
    int num;
    s.tos=-1; //empty stack initialized
    do
    {
        /* code */
        //clrscr();
        printf("\nSelect an option: \n1.Push\n2. Pop\n3. List\n4. Exit\n");
        fflush(stdin);
        choice=getche();
        switch(choice)
        {
            case '1':   printf("\nEnter a number:");
                        scanf("%d", &num);
                        if(push(&s, num))
                            printf("\nItem pushed into the stack successfully.");
                        else
                            printf("\nStack overflow. Pop some items before push.");
                        break;
            case '2':   if(isEmpty(&s))
                            printf("\nStack underflow. Push some items before pop.");
                        else
                        {
                            num=peek(&s);
                            pop(&s);
                            printf("\n%d was popped from the stack.", num);
                        }
                        break;
            case '3': break;
            case '4':
                printf("\nsorry to see go.");
                return 0;
        }

    } while (TRUE); //repeat forever

return 0;
}