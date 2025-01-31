#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct Stack
{
    int array[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int data)
{
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return INT_MIN;  
    }

    int popped = stack->array[stack->top];
    stack->top--;
    return popped;
}

int peek(Stack *stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;  
    }
    return stack->array[stack->top];
}

int size(Stack *stack)
{
    return stack->top + 1;  
}

void clear(Stack *stack)
{
    stack->top = -1;
    printf("Stack cleared.\n");
}

void printStack(Stack *stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    
    initializeStack(&stack);
    
    push(&stack, 2);
    push(&stack, 5);
    push(&stack, 6);
    
    printStack(&stack);  
    
    pop(&stack);
    printStack(&stack);  
    
    printf("Top element is %d\n", peek(&stack));  
    
    printf("Stack size is %d\n", size(&stack)); 
    
    clear(&stack);  
    printStack(&stack);  

    return 0;
}
