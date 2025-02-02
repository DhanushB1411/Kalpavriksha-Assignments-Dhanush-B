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

Node* merge(Node* ll1, Node* ll2)
{
    if (ll1 == NULL) return ll2;
    if (ll2 == NULL) return ll1;

    Node* ansNodeHead = NULL;
    Node* tail = NULL;  

    if (ll1->number < ll2->number) {
        ansNodeHead = ll1;
        ll1 = ll1->link;
    } else {
        ansNodeHead = ll2;
        ll2 = ll2->link;
    }

    tail = ansNodeHead;

    while (ll1 != NULL && ll2 != NULL) {
        if (ll1->number < ll2->number) {
            tail->link = ll1;
            ll1 = ll1->link;
        } else {
            tail->link = ll2;
            ll2 = ll2->link;
        }
        tail = tail->link; 
    }

    if (ll1 != NULL) {
        tail->link = ll1;
    } else {
        tail->link = ll2;
    }

    return ansNodeHead;
}



int main()
{

    Node* ll1 =NULL; 
    ll1 = insert_end(ll1,1);
    ll1 = insert_end(ll1,2);
    ll1 = insert_end(ll1,7);
    display(ll1);

    Node* ll2 =NULL; 
    ll2 = insert_end(ll2,3);
    ll2 = insert_end(ll2,4);
    ll2 = insert_end(ll2,6);
    display(ll2);

    Node * mergeLL = merge(ll1,ll2);
    display(mergeLL);

    return 0;
}