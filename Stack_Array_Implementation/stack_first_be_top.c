/*wap to demonstrate that the first element entered be at the top of the stack and last element to be popped*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int first=-1;

int isFull()
{
	if(first==MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if(first==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int data)
{
    int i;
	if(isFull())
	{
		printf("Stack overflow\n");
		return;
	}
    
    first=first+1;
    for(i=first; i>0; i--)
    {
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
	printf("%d pushed successfully\n", data);
}

int pop()
{
    int i;
	int value;
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	value=stack_arr[0];
    for(i=0; i<first; i++)
    {
        stack_arr[i]=stack_arr[i+1];
    }
	first=first-1;
	return value;
}


int peek()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stack_arr[first];
}

void print()
{
	int i;
	if(isEmpty())
	{
		printf("Stack underflow\n");
		return;
	}
	
	for(i=first; i>=0; i--)
	{
		printf("%d\n", stack_arr[i]);
	}
	printf("Successfully printed all the datas of the stack\n");
}

int main()
{
	int data, choice;
	
	while(1)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print the topmost data\n");
		printf("4. print all the data of the stack\n");
		printf("5. Quit\n");
		printf("\nEnter your choice: ");
		// scanf("%d", &choice);
        choice=getche();

        // Flush the input buffer
        // while ((getchar()) != '\n');
		
		switch(choice)
		{
			case 1:
				printf("Enter the data to be pushed: ");
				scanf("%d", &data);
				push(data);
				break;
				
			case 2:
				data = pop();
				printf("Popped data is %d\n", data);
				break;
				
			case 3:
				printf("The topmost data is %d\n", peek());
				break;
				
			case 4:
				print();
				break;
			
			case 5:
				exit(1);
			
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}