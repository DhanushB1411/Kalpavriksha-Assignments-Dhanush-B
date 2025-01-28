#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *head = NULL;

Node *create_node(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

void insertAtBeginning(int value)
{
    Node *newNode = create_node(value);

    newNode->link = head;
    head = newNode;
    return;
}

void insertAtEnd(int value)
{
    Node *newNode = create_node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = newNode;
}

void insertAtPosition(int position, int value)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    Node *newNode = create_node(value);

    if (position == 1)
    {
        newNode->link = head;
        head = newNode;
        return;
    }

    Node *temp = NULL;
    temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->link;
        if (temp == NULL)
            break;
    }

    if (temp == NULL)
    {
        printf(" out of range\n");
        free(temp);
    }
    else
    {
        newNode->link = temp->link;
        temp->link = newNode;
    }
}

void updateAtPosition(int position, int newValue)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    while (position > 1)
    {
        temp = temp->link;
        position--;
        if (temp == NULL)
            break;
    }

    if (temp == NULL)
    {
        printf("out of range \n");
        return;
    }
    temp->data = newValue;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf(" Empty list\n");
        return;
    }

    Node *temp = head;
    head = head->link;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    if (head->link == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    Node *prev = NULL;
    Node *temp = head;
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
}

void deleteAtPosition(int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }

    Node *prev = head;
    Node *next = head;
    while (position > 1)
    {
        prev = next;
        next = next->link;
        if (next == NULL)
            break;
        position--;
    }
    if (next == NULL)
    {
        printf("postion out of range node\n");
        return;
    }

    prev->link = next->link;
    free(next);
    return;
}
void display()
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

int main()
{

    int total_operation;
    scanf("%d", &total_operation);

    int input;

    for (int iteratorI = 0; iteratorI < total_operation; iteratorI++)
    {
        int operation = 1;
        scanf("%d", &operation);
        int value = 0, position = 0;
        switch (operation)
        {

        case 1:
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 2:
            scanf("%d", &value);
            insertAtBeginning(value);
            break;

        case 3:
            scanf("%d %d", &position, &value);
            insertAtPosition(position, value);
            break;

        case 4:
            display();
            break;

        case 5:
            scanf("%d %d", &position, &value);
            updateAtPosition(position, value);
            break;

        case 6:
            deleteAtBeginning();
            break;

        case 7:
            deleteAtEnd();
            break;

        case 8:
            scanf("%d", &position);
            deleteAtPosition(position);
            break;

        default:
            printf("Ivalid opeation\n");
            break;
        }
    }

    return 0;
}