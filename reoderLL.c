#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int number;
    struct node* link;
}Node;

Node * create_newNode(int number)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->number = number;
    newNode->link = NULL;

    return newNode;
}

Node *insert_end(Node* head, int number)
{
    Node* newNode = create_newNode(number);
    if(head == NULL)return newNode;

    Node* temp = head;

    while(temp->link !=NULL)
    {
        temp= temp->link;
    }

    temp->link = newNode;

    return head;
}

void display(Node* head)
{
    while(head !=NULL)
    {
        printf("%d ",head->number);
        head = head->link;
    }
    printf("\n");
}

Node* findLast(Node* head)
{
    Node* prev =NULL;
    while(head->link!=NULL)
    {
        prev = head;
        head = head->link;
    }

    prev->link = NULL;
    return head;

}

Node* reorder_ll(Node* head)
{
    Node* temp =head;
    while (temp!=NULL)
    {
        Node* lastNode = findLast(head);
    
        if(lastNode == temp)
        {
            temp->link = lastNode;
            break;
        }
        Node* tempNode = temp;
        temp = temp->link;
        tempNode->link = lastNode;
        lastNode->link = temp;
        //printf("lastNode : %d\n",tempNode->link->number);
    }

    return head;
}

int main()
{

    Node* ll1 =NULL; 
    ll1 = insert_end(ll1,1);
    ll1 = insert_end(ll1,2);
    ll1 = insert_end(ll1,3);
    ll1 = insert_end(ll1,4);
    ll1 = insert_end(ll1,5);
    display(ll1);

    ll1 = reorder_ll(ll1);
    display(ll1);

    return 0;
}