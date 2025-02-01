#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct Stack {
    int array[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int dequeue(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }

    int x = pop(stack);

    if (isEmpty(stack)) {
        return x;
    }

    int front = dequeue(stack);

    push(stack, x);

    return front;
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack queue;
    initializeStack(&queue);

    int choice, value;

    while (1) {
        printf("\nQueue using One Stack\n");
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
                push(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if (value != INT_MIN)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
