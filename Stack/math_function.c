/*
If stack is empty, display 
f(S) = 0

After pushing 1 into stack, display 
fnew(S) = max(fprevious(S), 0) + 1 = max(0, 0) + 1 = 1

Then push 2 into stack, display
fnew(S) = max(fprevious(S), 0) + 2 = max(1, 0) + 2 = 3

...and so on
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack
{
	int stack_array[MAX_SIZE];
	int top;
} stack;

void init()
{
	stack.top = -1;
}

int empty()
{
	if (stack.top == -1)
		return 1;
	else
		return 0;
}

int full()
{
	if (stack.top >= MAX_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(int e)
{
	if (full())
	{
		printf("Stack is full\n");
		exit(1);
	}
	else
	{
		stack.stack_array[stack.top + 1] = e;
		stack.top++;
	}
}

int pop()
{
	if (empty())
	{
		printf("Stack is empty\n");
		exit(1);
	}
	else
	{
		stack.top--;
		return stack.stack_array[stack.top + 1];
	}
}

int peek()
{
	if (!empty())
		return stack.stack_array[stack.top];
}

void print()
{
	if (!empty())
	{
		int tmp = pop();
		printf("fnew(S) = max(fprevious(S), 0) + %d = ", tmp);
		if (!empty())
		{
			int sum = peek() + tmp;
			printf("max(%d, 0) + ", peek());
			printf("%d = ", tmp);
			printf("%d\n\n", sum);
		}
		else
		{
			printf("max(0, 0) + %d = ", tmp);
			printf("%d\n\n", tmp);
		}
		push(tmp);
	}
	else
	{
		printf("f(S) = 0\n\n");
	}
}

int main()
{
	init(stack);
	int num;
	int menu = 0;

	while (menu != 4)
	{
		printf("Choose a number below\n");
		printf("1: Push number into the stack\n");
		printf("2: Pop number from the stack\n");
		printf("3: Display current stack\n");
		printf("4: Exit\n");
		scanf("%d", &menu);
		if (menu == 1 || menu == 2 || menu == 3 || menu == 4)
		{
			switch (menu)
			{
			case 1:
				printf("Enter a number to add to the stack: ");
				scanf("%d", &num);
				push(num);
				print();
				break;
			case 2:
				num = pop();
				print();
				break;
			case 3:
				print();
				break;
			case 4:
				printf("Goodbye...\n\n");
			}
		}
		else
			printf("Invalid input. Please try again\n\n");
	}

	return 0;
}