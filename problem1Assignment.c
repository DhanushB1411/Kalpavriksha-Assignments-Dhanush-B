#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum Complexity{
    ONE,
    LOG_N,
    N,
    N_LOG_N,
    N_POW_2,
    N_POW_K
}Complexity;

typedef struct node{
    Complexity timeComplexity;
    Complexity spaceComplexity;
    struct node* next;
}Node;


Complexity mapStringComplexity(char *complex){

    if(strcmp(complex,"1")==0){
        return ONE;
    }
    else if(strcmp(complex,"logn")==0){
        return LOG_N;
    }
    else if(strcmp(complex,"n")==0){
        return N;
    }
    else if(strcmp(complex,"nlogn")==0){
        return N_LOG_N;
    }
    else if(strcmp(complex,"n^2")==0){
        return N_POW_2;
    }
    else if(strcmp(complex,"n^k")==0){
        return N_POW_K;
    }
}


Node* insert_at_end(Node* head,Complexity tc, Complexity sc){
    
    Node* newNode = malloc(sizeof(Node));
    newNode->spaceComplexity = sc;
    newNode->timeComplexity =tc;
    newNode->next =NULL;

    Node* temp =head;

    if(temp ==NULL){
        return newNode;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

char* mapComplexityString(Complexity c){
    
    if(c==0){
        return "1";
    }
    else if(c==1){
        return "logn";
    }
    else if(c==2){
        return "n";
    }else if(c==3){
        return "nlogn";
    }else if(c==4){
        return "n^2";
    }else if(c==5){
        return "n^k";
    }
    
}

Node* findMid(Node* head){
    Node* slow= head;
    Node* fast = head;
    if(slow->next ==NULL)return head;
    while(fast->next!=NULL && fast->next->next !=NULL){
        slow= slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* firstHalf,Node* secondHalf){

    Node* tail =NULL;
    Node* headNode =NULL;
    if(firstHalf->timeComplexity == secondHalf->timeComplexity){
        if(firstHalf->spaceComplexity<secondHalf->spaceComplexity){
            tail = firstHalf;
            headNode =firstHalf;
            firstHalf = firstHalf->next;

        }else{
            tail = secondHalf;
            headNode = secondHalf;
            secondHalf= secondHalf->next;
        }
    }
    else if(firstHalf->timeComplexity<secondHalf->timeComplexity){
        tail = firstHalf;
        headNode = firstHalf;
        firstHalf = firstHalf->next;
    }else{
        tail = secondHalf;
        headNode= secondHalf;
        secondHalf = secondHalf->next;
    }

    while (firstHalf !=NULL && secondHalf !=NULL)   
    {

        if(firstHalf->timeComplexity == secondHalf->timeComplexity){
            if(firstHalf->spaceComplexity<=secondHalf->spaceComplexity){
                tail->next = firstHalf;
                firstHalf = firstHalf->next;
            }else{
                tail->next = secondHalf;
                secondHalf= secondHalf->next;
            }
            tail = tail->next;
        }
        else if(firstHalf->timeComplexity<secondHalf->timeComplexity){
            tail->next = firstHalf;
            tail = tail->next;
            firstHalf= firstHalf->next;
        }else{
            tail->next = secondHalf;
            tail =tail->next;
            secondHalf = secondHalf->next;
        }
    }

    if(secondHalf == NULL){
        tail->next =firstHalf;
    }

    if(firstHalf == NULL){
        tail->next =secondHalf;
    }

    return headNode;
}
void display(Node* head){
    
    while (head!=NULL)
    {
        printf("%s %s\n",mapComplexityString(head->timeComplexity),mapComplexityString(head->spaceComplexity));
        head = head->next;
    }
    
}
Node* sort(Node* head){

    if(head->next ==NULL)return head;

    Node* midNode = findMid(head);
    Node* firstHalf = head;
    Node* secondHalf = midNode->next;
    midNode->next =NULL;

    firstHalf = sort(firstHalf);
    secondHalf = sort(secondHalf);
    
    printf("firstHalf :\n");
    display(firstHalf);
    printf("SecondHalf : \n");
    display(secondHalf);
    Node* merged = merge(firstHalf,secondHalf);
    printf("Sorted:\n");
    display(merged);
    return merged;
}


int main(){
    
    int noTimes;
    scanf("%d",&noTimes);
    Node* head=NULL;

    for(int i=0;i<noTimes;i++){
        char tc[100];
        char sc[100];

        scanf("%s %s",tc,sc);
        Complexity timeComp = mapStringComplexity(tc);
        Complexity spaceComp = mapStringComplexity(sc);

        head = insert_at_end(head,timeComp,spaceComp);
    }
    //display(head);

    head = sort(head);
    //printf("head : %d %d\n",head->timeComplexity,head->spaceComplexity);
    printf("\n Final sorted:\n");
    display(head);
    return 0;
}