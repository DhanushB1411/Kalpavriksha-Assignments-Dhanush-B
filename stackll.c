#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} Node;

Node *top = NULL;

Node * create_new_node(int data)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

void push(int data)
{
    
    Node* newNode =  create_new_node(data);

    if(top == NULL)
    {
        top = newNode;
        return;
    }

    newNode->link = top;
    top = newNode;
    
}

void display()
{
    Node* temp =top;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}


void pop()
{
    if(top== NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    free(temp);
    top = top->link;
}
int main()
{

    push(3);
    push(6);
    push(10);
    display();
    pop();
    printf("%d \n",top->data);
    display();

    return 0;
}