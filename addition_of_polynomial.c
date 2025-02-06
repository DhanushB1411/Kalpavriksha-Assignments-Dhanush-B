#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float coeffient;
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
    while(temp != NULL && temp->power > pow)
    {
        prev = temp;
        temp = temp->link;
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
            printf("%.1fx",poly->coeffient);

        }else if(poly->power == 0)
        {
            printf("%.1f",poly->coeffient);
        }else
            printf("%.1fx^%d",poly->coeffient,poly->power);
        
        poly = poly->link;
        if(poly !=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

Node* addPoly(Node* poly1 ,Node* poly2)
{
    Node* polyHead = NULL;

    while(poly1 !=NULL && poly2 !=NULL)
    {
        
        if(poly1->power>poly2->power){

            polyHead = insert(poly1->coeffient,poly1->power,polyHead);
            poly1 =poly1->link;
        }
        else if(poly1->power<poly2->power)
        {
            polyHead = insert(poly2->coeffient,poly2->power,polyHead);
            poly2 =poly2->link;
        }else{
            polyHead = insert(poly1->coeffient+poly2->coeffient,poly1->power,polyHead);
            poly1 =poly1->link;
            poly2 = poly2->link;
        }
    }

    while(poly1!=NULL)
    {
        polyHead = insert(poly1->coeffient,poly1->power,polyHead);
        poly1=poly1->link;
    }

    while(poly2!=NULL)
    {
        polyHead = insert(poly2->coeffient,poly2->power,polyHead);
        poly2=poly2->link;
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

    Node * newpoly = addPoly(poly1,poly2);

    display(newpoly);

    return 0;
}