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

Node *add_number(Node* head, int number)
{
    Node* newNode = create_newNode(number);
    if(head == NULL)return newNode;

   newNode->link =head;
   head = newNode;
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


Node* reverseLinkedList(Node* head)
{
    if(head == NULL || head->link == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *current = head;

    while(current !=NULL)
    {
        Node* temp = current->link;
        current->link = prev;
        
        prev = current;

        current = temp;
    }

    return  prev;
}

Node* addNumbers(Node* num1, Node* num2)
{

    int sum=0;
    int carry =0;
    Node * added =NULL;

    while(num1 !=NULL || num2 !=NULL){
        sum =0;
        if(num1 !=NULL)
        {
            sum += num1->number;
        }
        if(num2 !=NULL)
        {
            sum += num2->number;
        }
        sum = sum+carry;
        carry = sum/10;
        sum = sum%10;

        added = add_number(added,sum);

        if(num1 !=NULL)
        num1 = num1->link;
        
        if(num2 !=NULL)
        num2 = num2->link;

    }

    if(carry)
    {
        added = add_number(added,carry);
    }

    return added;

}

Node * mulNum(Node* num1, Node* num2)
{
    Node* addnum1 =NULL;
    Node* addnum2 =NULL;

    Node* temp1 =num1;
    Node* temp2 = num2;
    while(temp2!=NULL)
    {

        while(temp1 !=NULL)
        {
            
        }
    }
}
int main()
{

    int num1 =457;
    scanf("%d",&num1);
    Node * num1Head =NULL;

    while(num1 !=0)
    {
        num1Head = add_number(num1Head,num1%10);
        num1 = num1/10;
    }
    display(num1Head);

    num1Head = reverseLinkedList(num1Head);

    int num2 = 669;
    scanf("%d", &num2);
    Node * num2Head =NULL;

    while(num2 !=0)
    {
        num2Head = add_number(num2Head,num2%10);
        num2 = num2/10;
    }
    display(num2Head);

    num2Head = reverseLinkedList(num2Head);
    
    Node* mulNum = muldNumbers(num1Head,num2Head);
    
    display(mulNum);
    return 0;
}