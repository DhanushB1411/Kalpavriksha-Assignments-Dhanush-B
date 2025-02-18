#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}Node;

Node* createNewNode(int data){
    Node* newNode = malloc(sizeof(Node));

    newNode->data =data;
    newNode->prev =NULL;
    newNode->next =NULL;

    return newNode;
}

 Node* insertAtLast(Node* head,int data){

    Node* temp =head;
    Node* newNode =createNewNode(data);
    
    if(head ==NULL){
        return newNode;   
    }

    while(temp->next!=NULL){
        temp =temp->next;
    }

    temp->next =newNode;
    newNode->prev = temp;

    return head;

 }

 Node* insertAtBeg(Node* head, int data){
    Node* temp =head;
    Node* newNode =createNewNode(data);
    
    if(head ==NULL){
        return newNode;   
    }

    head->prev = newNode;
    newNode->next = head;

    head = newNode;
    return head;
 }

 Node* insertAtpos(Node* head, int data , int pos){
    
    if(pos ==1){
       Node* temp = insertAtBeg(head,data);
        return temp;
    }
    Node* temp =head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
        if(temp->next == NULL)break;
    }

    
    Node* newNode = createNewNode(data);
    if(temp==NULL || temp->next ==NULL){
        temp->next = newNode;
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next =newNode;
    
    return head;

 }
void display(Node* head)
{
    Node* temp =head;

    while(temp !=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    Node* head =NULL;
    head = insertAtLast(head,22);
    head = insertAtLast(head,23);
    head = insertAtLast(head,233);

    head = insertAtBeg(head,110);
    head = insertAtBeg(head,1001);
    display(head);
    head = insertAtpos(head,99999,7);
    display(head);
}