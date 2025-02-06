
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode* temp = head;
    int *stack = NULL;
    int size = 0;
    
    while (temp != NULL) {
        stack = (int *)realloc(stack, (size + 1) * sizeof(int));
        stack[size++] = temp->val;
        temp = temp->next;
    }

    temp = head;
    // Check if the list is a palindrome
    while (temp != NULL) {
        if (stack[--size] != temp->val) {
            free(stack); // Free the allocated memory
            return false;
        }
        temp = temp->next;
    }
    
    free(stack); // Free the allocated memory
    return true;
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 2 -> 1
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Free the allocated memory
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
