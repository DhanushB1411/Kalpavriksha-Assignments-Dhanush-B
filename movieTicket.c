#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char movieName[100];
    int seatNum;
    int screenName;
    struct node *next;
    char status[100];
}Node;

Node* createNewNode(char *movieName,int seatNum, int screenName)
{
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->movieName,movieName);
    strcpy(newNode->status,"Pending");
    newNode->seatNum = seatNum;
    newNode->screenName = screenName;
    newNode->next =NULL;

    return newNode; 
}

void enqueueBook(Node** bookFront,Node ** bookRear,char *movieName,int seatNum, int screenName)
{
    Node* newNode =  createNewNode(movieName,seatNum,screenName);
    if(*bookFront==NULL && *bookRear ==NULL)
    {
        *bookFront =newNode ;
        *bookRear = newNode;
        return;
    }

    (*bookRear)->next = newNode;
    (*bookRear) =(*bookRear)->next;

    return ;

}

void ApproveQueue(Node* bookNode,Node **aproveFront, Node** aproveRear)
{
    strcpy(bookNode->status,"Approved");        
    if(*aproveFront==NULL && *aproveRear ==NULL)
    {
        *aproveFront =bookNode ;
        *aproveRear = bookNode;
        return ;
    }

    
    (*aproveRear)->next = bookNode;
    (*aproveRear) =(*aproveRear)->next;

    return ;
}

void dequeueBook(Node **bookFront, Node **bookRear,Node **aproveFront, Node** aproveRear)
{
    Node *temp = *bookFront;
    if(*bookFront == NULL){
        printf("No element to delete\n");
        return;
    }
    printf("Approved Successfully of : ");
    printf("%s\t%d\t %d\t%s\n",temp->movieName,temp->screenName,temp->seatNum,temp->status);
    *bookFront = (*bookFront)->next;
    temp->next =NULL;

    ApproveQueue(temp,aproveFront,aproveRear);

}


void display(Node* head)
{
    if(head ==NULL){
        printf("No element in the queue\n");
        return;
    }
    while(head!=NULL)
    {
        printf("%s\t%d\t %d\t%s\n",head->movieName,head->screenName,head->seatNum,head->status);
        head = head->next;
    }

    printf("\n");
}



int main()
{
    Node* bookFront=NULL;
    Node* bookRear = NULL;
    Node* approveFront =NULL;
    Node* approveRear =NULL;
    int ch;
    char str[100];
    int sn;
    int sen;
    while(1){
    printf("enter choice :\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
       
        printf("Enter movie name\t screenNum\t seatNum\n");
        scanf(" %[^\n]",str);
        scanf("%d",&sn);
        scanf("%d",&sen);
        enqueueBook(&bookFront,&bookRear,str,sn,sen);
        break;

    case 2:
        display(bookFront);
        break;

    case 3:
        dequeueBook(&bookFront,&bookRear,&approveFront,&approveRear);
        break;
    
    case 4:
        display(approveFront);
        break;
    
    default:exit(0);
        break;
    }

    }
}