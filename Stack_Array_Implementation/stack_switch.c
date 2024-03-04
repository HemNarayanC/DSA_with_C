#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top=-1;

int isFull()
{
	if(top==MAX-1)
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
	if(top==-1)
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
	if(isFull())
	{
		printf("Stack overflow\n");
		return;
	}
	top=top+1;
	stack_arr[top]=data;
	printf("%d pushed successfully\n", data);
}

int pop()
{
	int value;
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	value=stack_arr[top];
	top=top-1;
	return value;
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stack_arr[top];
}

void print()
{
	int i;
	if(isEmpty())
	{
		printf("Stack underflow\n");
		return;
	}
	
	for(i=top; i>=0; i--)
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
		scanf("%d", &choice);
		
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