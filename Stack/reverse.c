// Reverse the order

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack
{
    char stack_array[MAX_SIZE];
    char top;
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

void push(char e)
{
    if (full())
    {
        printf("Stack is full\n");
        exit(1);
    }
    else
    {
        stack.stack_array[stack.top+1] = e;
        stack.top++;
    }
}

char pop()
{
    if (empty())
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        stack.top--;
        return stack.stack_array[stack.top+1];
    }
}

void print()
{
    if (!empty())
    {
        char tmp = pop();
        print();
        printf("%c ", tmp);
        push(tmp);
    }
}

void bottom_insert(char e)
{
    if (empty())
        push(e);
    else
    {
        char tmp = pop();
        bottom_insert(e);

        // Push top element back after inserting at the bottom
        push(tmp);
    }
}

void reverse()
{
    if (!empty())
    {
        // Empty stack
        char tmp = pop();
        reverse();

        // Insert elements at the bottom
        bottom_insert(tmp);
    }
}

int main(void)
{
    init(stack);
    push('d');
    push('r');
    push('a');
    push('w');
    push('e');
    push('r');
    print();
    printf("\n");

    printf("Reversing stack...\n");
    reverse();
    print();
    printf("\n");

    return 0;
}
