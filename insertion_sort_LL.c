#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float data;
    struct node *link;
} Node;

Node *create_node(float data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

Node* insertAtBeginning(float value, Node* head)
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
        printf("%.2f ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

Node* insertionSort(Node *head)
{
    if (head == NULL || head->link == NULL)
    {
        return head;
    }

    Node *sorted = NULL;
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->link;
        
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->link = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->link != NULL && temp->link->data < current->data)
            {
                temp = temp->link;
            }
            current->link = temp->link;
            temp->link = current;
        }
        
        current = next;
    }

    return sorted;
}

int main()
{
    Node *head = NULL;

    head = insertAtBeginning(5.4, head);
    head = insertAtBeginning(3.2, head);
    head = insertAtBeginning(8.1, head);
    head = insertAtBeginning(2.3, head);
    head = insertAtBeginning(4.9, head);
    head = insertAtBeginning(7.6, head);

    printf("Linked list before sorting:\n");
    display(head);

    head = insertionSort(head);

    printf("Linked list after sorting:\n");
    display(head);

    return 0;
}
