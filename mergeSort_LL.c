#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float data;
    struct node *link;
} Node;

Node* create_node(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

Node* insertAtBeginning(float value, Node* head) {
    Node* newNode = create_node(value);
    newNode->link = head;
    return newNode;
}

void display(Node* head) {
    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%.2f ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

Node* getMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast->link != NULL && fast->link->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;
    }
    
    return slow;
}

Node* merge(Node* left, Node* right) {
  
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->link == NULL) return head;

    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->link;

    middle->link = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextOfMiddle);

    return merge(left, right);
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(5.4, head);
    head = insertAtBeginning(3.2, head);
    head = insertAtBeginning(8.1, head);
    head = insertAtBeginning(2.3, head);
    head = insertAtBeginning(4.9, head);
    head = insertAtBeginning(7.6, head);

    printf("Linked list before sorting:\n");
    display(head);

    head = mergeSort(head);

    printf("Linked list after sorting:\n");
    display(head);

    return 0;
}
