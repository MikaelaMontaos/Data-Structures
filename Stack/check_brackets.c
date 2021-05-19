/* 
Detect and label unmatched brackets

Labels:
$ = Unmatched left bracket
? = Unmatched right bracket
*/

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

char peek() {
    if(!empty())
        return stack.stack_array[stack.top];
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

void check_bracket()
{
    init(stack);
    char c, top;

    printf("Enter a string (ENTER when done):\n");
    while (c != '\n')
    {
        scanf("%c", &c);
        if(c == '(' || c == '{' || c == '[')
            push(c);
        else if(c == ')' || c == '}' || c == ']') {
            if(c == ')') {
                if(peek() == '(') {
                    pop();
                    printf(" ");
                }
                else 
                    printf("?");
            }
            if(c == ']') {
                if(peek() == '[') {
                    pop();
                    printf(" ");
                }
                else
                    printf("?");
            }
            if(c == '}') {
                if(peek() == '{') {
                    pop();
                    printf(" ");
                }
                else
                    printf("?");
            }
        }
        else
            printf(" ");
    }
    
    if(!empty()) {
        if(peek() == '(' || peek() == '{' || peek() == '[')
            printf("$");
        else
            printf("?");
    }

    printf("\n");
}

int main(void)
{
    check_bracket();
    printf("Finished checking brackets...\n");

    return 0;
}