#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *create_node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

Node* insertAtBeginning(int value, Node* head)
{
    Node *newNode = create_node(value);
    newNode->link = head;
    head = newNode;
    return head;
}

void display(Node* head)
{
    if (head == NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

Node* swap(Node *prev, Node* node1, Node* node2, Node* head)
{
    node1->link = node2->link;
    node2->link = node1;
    if (prev == NULL) 
    {
        head = node2; 
    }
    else
    {
        prev->link = node2;
    }

    return head;
}

Node *bubbleSort(Node *head)
{
    if (head == NULL || head->link == NULL)
    {
        return head; 
    }

    int swapped;
    do
    {
        swapped = 0;
        Node *current = head;
        Node *prev = NULL; 

        while (current->link != NULL) 
        {
            if (current->data > current->link->data)
            {
                head = swap(prev, current, current->link, head); 
                swapped = 1;
              
            } else {
                prev = current; 
                current = current->link;
            }
        }

    } while (swapped);

    return head;
}

int main()
{
    Node *head = NULL;

    // Inserting nodes
    head = insertAtBeginning(44, head);
    head = insertAtBeginning(55, head);
    head = insertAtBeginning(33, head);
    head = insertAtBeginning(25,head);
    head = insertAtBeginning(11, head);
    head = insertAtBeginning(22, head);

    // Displaying the list before sorting
    printf("Linked list before sorting:\n");
    display(head);

    // Sorting the linked list using bubble sort
    head = bubbleSort(head);

    // Displaying the list after sorting
    printf("Linked list after sorting:\n");
    display(head);

    return 0;
}