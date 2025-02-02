#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeffient;
    int power;
    struct node* link;
}Node;

Node * create_newNode(float coef,int pow)
{
    Node * newNode = malloc(sizeof(Node));

    newNode->coeffient = coef;
    newNode->power = pow;
    newNode->link = NULL;

    return newNode;
}

Node* insert(float coef,int pow,Node *head)
{
    Node* newNode = create_newNode(coef,pow);
    if(head==NULL)return newNode;

    Node* temp = head;
    if(temp->power<pow)
    {
        newNode->link = temp;
        head = newNode;
        return head;
    }

    Node* prev =NULL;
    while(temp != NULL && temp->power >= pow)
    {
        prev = temp;

        temp = temp->link;
    }

     if(prev->power == pow)
    {
        prev->coeffient = prev->coeffient+coef;
        free(newNode);
        return head;
    }

    if(temp == NULL)
    {
        prev->link = newNode;
        return head;
    }

   

    prev->link = newNode;
    newNode->link = temp;

    return head;
}

void display(Node *poly)
{
    while(poly !=NULL)
    {
        if(poly->power == 1)
        {
            printf("%dx",poly->coeffient);

        }else if(poly->power == 0)
        {
            printf("%d",poly->coeffient);
        }else
            printf("%dx^%d",poly->coeffient,poly->power);
        
        poly = poly->link;
        if(poly !=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

Node* mulPoly(Node* poly1 ,Node* poly2)
{
    Node* polyHead = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;
    
    while( temp1 != NULL)
    {       
        temp2 = poly2;
        while (temp2 !=NULL)
        {
            polyHead = insert(temp1->coeffient *temp2->coeffient, temp1->power+temp2->power,polyHead);
            temp2 = temp2->link;
        }

        temp1 = temp1->link;
    }

    return polyHead;
}

int main(){
    
    Node *poly1  = NULL;
    printf("Enter the first polynomial\n");
    printf("enter the number of terms : ");
    int noTerms =0;

    float coeffi=0.0;
    int power = 0;
    scanf("%d",&noTerms);

    for(int i=0;i<noTerms;i++)
    {
        scanf("%f %d",&coeffi,&power);
        poly1 = insert(coeffi,power,poly1);
    }

    Node *poly2  = NULL;
    printf("Enter the second polynomial");
    printf("enter the number of terms");
   
    scanf("%d",&noTerms);

    for(int i=0;i<noTerms;i++)
    {
        scanf("%f %d",&coeffi,&power);
        poly2 = insert(coeffi,power,poly2);
    }
    
    display(poly1);
    display(poly2);

    Node * newpoly = mulPoly(poly1,poly2);
    Node * mulpoly = newpoly;
    display(newpoly);

    return 0;
}