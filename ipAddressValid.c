#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node{
    int number;
    struct node* next;
}Node;

bool checkValidLLIpv4(Node* head){
    int count=0;
    while(head !=NULL){
        if( head->number>255 ){
            return false;
        }
        count++;
        head = head->next;
    }

    if(count ==4){
        return true;
    }

    return false;
}

Node* insert_atLast(Node* head, int number)
{
    Node* newNode = (Node* )malloc(sizeof(Node));
    newNode->number =number;
    newNode->next =NULL;

    if(head ==NULL){
        return newNode;
    }

    Node* temp =head;
    while(temp->next !=NULL){
        temp = temp->next;
    }

    temp->next =  newNode;

    return head;
    
}

void display(Node* head){
    while (head !=NULL)
    {
        printf(" %d",head->number);
        head = head->next;
    }
    printf("\n");
    
}

bool checkIPv4(char* input){

    int size = strlen(input);
    int number =0;
    
    Node* head =NULL;
    
    while (*input)
    {   
       // printf("in : %c\n",*input);
        if( (*input)>= '0' && (*input) <='9'){
            number = number*10 + (*input) - '0';
        }else if( (*input) == '.' || (*input )== '\0'){
            head = insert_atLast(head,number);
           // printf("num : %d \n",number);
            number =0;
        }else{
            return false;
        }
        
        input++;
        if(*input == '\0'){
            if(number>0){
                head = insert_atLast(head,number);
            }
           // printf("num : %d\n",number);
        }
    }
    bool ans = checkValidLLIpv4(head);
    return ans;
}

bool checkValidLLIpv6(Node* head){
    int count = 0;
    while (head != NULL) {
        if (head->number > 0xFFFF) {
            return false;
        }
        count++;
        head = head->next;
    }
    return count == 8;
}

bool checkIPv6(char *input){
    Node* head = NULL;
    char buffer[5];
    int index = 0;
    int value = 0;
    
    while (*input) {
        if ((*input >= '0' && *input <= '9') || (*input >= 'a' && *input <= 'f') || (*input >= 'A' && *input <= 'F')) {
            value = value * 16 + ((*input >= '0' && *input <= '9') ? (*input - '0') : ((*input & 0xDF) - 'A' + 10));
        } else if (*input == ':' || *input == '\0') {
            head = insert_atLast(head, value);
            value = 0;
        } else {
            return false;
        }
        input++;
    }
    if (value > 0) {
        head = insert_atLast(head, value);
    }
    return checkValidLLIpv6(head);
}

int main(){
    char input[1000];
    scanf(" %[^\n]",input);

    bool ipv4 = checkIPv4(input);

    if(ipv4){
        printf("IPv4\n");
        exit(0);
    }

    bool ipv6 = checkIPv6(input);

    if(ipv6){
        printf("IPv6\n");
        exit(0);
    }
    
    printf("Neither\n");
    
    return 0;
}
