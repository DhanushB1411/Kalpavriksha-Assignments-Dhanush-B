#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *link;
} Node;

Node *create_node(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

Node* insertAtBeginning(char value, Node* head)
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
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

Node* selectionSort(Node *head)
{
    if (head == NULL || head->link == NULL)
    {
        return head; 
    }

    Node *i, *j;
    for (i = head; i != NULL; i = i->link)
    {
        Node *min = i;
        for (j = i->link; j != NULL; j = j->link)
        {
            if (j->data < min->data)
            {
                min = j;
            }
        }

        // Swap data between i and min
        if (min != i)
        {
            char temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }

    return head;
}

int main()
{
    Node *head = NULL;

    head = insertAtBeginning('F', head);
    head = insertAtBeginning('E', head);
    head = insertAtBeginning('C', head);
    head = insertAtBeginning('A', head);
    head = insertAtBeginning('D', head);
    head = insertAtBeginning('B', head);

    printf("Linked list before sorting:\n");
    display(head);

    head = selectionSort(head);

    printf("Linked list after sorting:\n");
    display(head);

    return 0;
}
