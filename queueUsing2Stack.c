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

int count=0;

void push1(Stack *s1,int  data)
{
    s1->array[++s1->top] = data;
}
void enqueue(Stack *s1,int x)
{
     if (isFull(s1)) {
        printf("Queue Overflow\n");
        return;
    }
    push1(s1,x);
    count++;
}

void dequeue(Stack *s1,Stack *s2)
{
    if(isEmpty(s1) && isEmpty(s2)){
        printf("No element\n");
        return;
    }
    while(!isEmpty(s1))
    {
        push(s2,peek(s1));
        pop(s1);
    }

    printf("deleted : %d\n",peek(s2));
    pop(s2);

     while(!isEmpty(s2))
    {
        push(s1,peek(s2));
        pop(s2);
    }

}

void display(Stack *s1) {
    if (isEmpty(s1)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = 0; i <= s1->top; i++) {
        printf("%d ", s1->array[i]);
    }
    printf("\n");
}

int main() {
    Stack s1, s2;
    initializeStack(&s1);
    initializeStack(&s2);

    int choice, value;

    while (1) {
        printf("\nQueue using Two Stacks\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&s1, value);
                break;
            case 2:
                dequeue(&s1, &s2);
                break;
            case 3:
                display(&s1);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}