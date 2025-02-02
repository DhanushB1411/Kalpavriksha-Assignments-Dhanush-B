#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* link;
} Node;

// Function to create a new node
Node* create_newNode(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    newNode->link = NULL;
    return newNode;
}

// Function to insert at the end of the list
Node* insert_end(Node* head, int number) {
    Node* newNode = create_newNode(number);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return head;
}

void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head->number);
        head = head->link;
    }
    printf("\n");
}


Node* rearrangeLL(Node* head)
{
    if(head ==NULL || head->link == NULL)return head;
    Node* oddll = head;
    Node* tevenll = head->link;
    Node* evenll = head->link;

    
    while(oddll!=NULL && evenll !=NULL)
    {
        if(oddll->link ==NULL){
            oddll->link = NULL;
        }
        else{
            oddll->link = oddll->link->link;
            printf("%d\n",oddll->number);
        }
        if(evenll->link ==NULL){
            evenll->link = NULL;
        }else{
        evenll->link = evenll->link->link;
            printf("%d\n",evenll->number);

        }

        oddll = oddll->link;
        evenll= evenll->link;       
    }
    
   
    Node* temp =head;
    while (temp->link !=NULL)       
    {
        temp = temp->link;  
    }
    
    printf("odd %d\n",temp->number);
    temp->link = tevenll;

    return head;
}

int main() {
    Node* ll1 = NULL;
    ll1 = insert_end(ll1, 1);
    ll1 = insert_end(ll1, 2);
     ll1 = insert_end(ll1, 3);
    // ll1 = insert_end(ll1, 4);
    // ll1 = insert_end(ll1, 5);
    // ll1 = insert_end(ll1,6);
    // ll1 = insert_end(ll1,7);
    
    printf("Original List: ");
    display(ll1);

    rearrangeLL(ll1);

    printf("REarranged List: ");
    display(ll1);

    return 0;
}
