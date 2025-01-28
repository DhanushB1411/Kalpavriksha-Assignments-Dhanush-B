#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node * link;
}Node;


Node * create_new_node(int data)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

Node * insert_at_last(Node *head,int data)
{
    Node* newNode = create_new_node(data);

    Node* ptr = head;
    if(head == NULL)
    {
        return newNode;
    }

    while(ptr->link !=NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = newNode;

    return head;
}


void print_nodes(Node *head)
{

    if(head == NULL)
    {
        printf("empty\n");
        return;
    }
    while(head !=NULL)
    {
        printf("%d ",head->data);
        head = head->link;
    }
    printf("\n");
}

Node * addEle(Node* head,int data)
{
    Node * newNode = create_new_node(data);

         if(head->data > data){
            newNode->link = head;
            head=newNode;
            return head;
         }
     
    Node* temp =head;

    while( temp -> link !=NULL && temp->link->data < data )
    {
        temp = temp->link;
    }
  

    newNode->link = temp->link;
    temp->link = newNode;
    

    return head;
}

int main()
{
    Node *head = NULL;
    head = insert_at_last(head,24);
    
    head = insert_at_last(head,45);
    head = insert_at_last(head,56);
    head = insert_at_last(head,100);
   

    print_nodes(head);
    head = addEle(head, 101);

    print_nodes(head);

}