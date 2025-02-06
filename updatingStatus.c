#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum status {Raised, waiting ,Processed };

typedef struct  node
{
    int empId;
    char issue[100];
    enum status st;
    struct node* next;
}Node;

Node* create_new_node(int eI,char *issus,enum status status)
{
    Node* newNode= malloc(sizeof(Node));
    newNode->empId = eI;
    strcpy(newNode->issue,issus);
    newNode->st =status;
    newNode->next =NULL;
}
Node* insert_end(Node* head,int eI,char *issus)
{

    Node *newNode = create_new_node(eI,issus,Raised);
    if(head ==NULL)
    {
        return newNode;   
    }

    Node* temp =head;
    while (temp->next !=NULL)   
    {
        temp = temp->next;
    }

    temp->next = newNode;
    
    return head;
}


void display(Node * head)
{
    while(head!=NULL)
    {
        printf("%d\t%s\t%d\n",head->empId,head->issue,head->st);
        head =head->next;
    }
    printf("\n");
    return ;
}

Node* findEmp(Node* head, int empId)
{
    Node* temp= head;

    while(temp!=NULL && temp->empId !=empId)
    {
        temp =temp->next;
    }

    temp->st =1;
    return head;
}
int main()
{
    Node * head =NULL;
    head = insert_end(head,1,"Need dayOff");
    head = insert_end(head,2,"Need somethind");
    head = insert_end(head,4,"laptop issuse");

    display(head);
    head = findEmp(head,2);
    display(head);
}