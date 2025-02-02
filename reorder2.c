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

// Function to display the list
void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head->number);
        head = head->link;
    }
    printf("\n");
}

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev; // New head of the reversed list
}

// Function to reorder the linked list
void reorder_ll(Node* head) {
    if (head == NULL || head->link == NULL) return;

    // Step 1: Find the middle of the list
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;
    }

    // Step 2: Reverse the second half of the list
    Node* secondHalf = reverse(slow->link);
    slow->link = NULL; // Break the list into two halves

    // Step 3: Merge both halves alternately
    Node* firstHalf = head;
    Node* temp;
    while (firstHalf != NULL && secondHalf != NULL) {
        temp = firstHalf->link;
        firstHalf->link = secondHalf;
        firstHalf = temp;

        temp = secondHalf->link;
        secondHalf->link = firstHalf;
        secondHalf = temp;
    }
}

// Driver function
int main() {
    Node* ll1 = NULL;
    ll1 = insert_end(ll1, 1);
    ll1 = insert_end(ll1, 2);
    ll1 = insert_end(ll1, 3);
    ll1 = insert_end(ll1, 4);
    ll1 = insert_end(ll1, 5);

    printf("Original List: ");
    display(ll1);

    reorder_ll(ll1);

    printf("Reordered List: ");
    display(ll1);

    return 0;
}
