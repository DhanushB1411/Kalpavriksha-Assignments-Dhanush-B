#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 10

typedef struct node
{
    int key;
    int value;
    struct node* next;
}Node;

Node *hashTable[TABLE_SIZE];

int hashFunction(int key){
    return key % TABLE_SIZE;
}

void insert(int key,int value)
{
    int index = hashFunction(key);
    Node* current = hashTable[index];

    while (current !=NULL){
        if(current->key == key)
        {
            current->value = value;
            return;
        }

        current = current->next;
    }
    

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key){
    int index = hashFunction(key);
    Node* current = hashTable[index];

    while(current!=NULL)
    {
        if(current->key ==key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void delete(int key)
{
    int index = hashFunction(key);
    Node* current = hashTable[index];
    Node* prev =NULL;

    while (current !=NULL)
    {
        if(current->key == key){
            if(prev ==NULL){
                hashTable[index] = current->next;
            }else
            {
                prev->next = current->next;
            }

            free(current);
            printf("Key %d deleted.\n",key);
            return;
        }

        prev = current;
        current =current->next;
    }

    printf("Key %d not found.\n",key);

}


void display(){
    printf("Hash Table :\n");

    for(int i=0;i<TABLE_SIZE;i++)
    {
        printf("Index %d: ",i);

        Node* current = hashTable[i];

        while( current !=NULL){
            printf(" (%d, %d) ->",current->key, current->value);
                current = current->next;
        }
        printf(" NULL\n");
    }
}
int main()
{
    int choice, key,value;
    int exit=0;

    while (1)
    {
        printf("\n 1.Insert\n 2.Serach\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(key,value);
            //printf("%d %d\n" ,hashTable[0]->value,hashTable[0]->next->value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            value = search(key);
            if(value == -1)
                printf("Key not found\n");
            else
                printf("value : %d\n",value);
            break;

        case 3: 
             printf("Enter key: ");
                scanf("%d", &key);
                delete(key);
                break;
        case 4: 
            display();
            break;
        case 5:
            printf("Exiting Program. \n");
            return 0;
        
        default: printf("Invalid choice. Try again.\n");
            break;
        }
     //   if(exit == 1)break;
    }

    
    return 0;
}