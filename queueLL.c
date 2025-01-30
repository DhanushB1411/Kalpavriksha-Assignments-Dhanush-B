#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} Node;

Node *front = NULL;
Node *rear = NULL;

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

    if(front == NULL && rear ==NULL)
    {
        front  = newNode;
        rear = newNode;
        return;
    }

    rear->link = newNode;
    rear = newNode;
     
}

void display()
{
    Node* temp =front;
    if(temp == NULL)return;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}


void pop()
{
    if(front== NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = front;
    front = front->link;
    free(temp);
}
int main()
{

    push(11);
    push(22);
    push(33);
    display();
    pop();
    display();
    return 0;
}