#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    char name[10];  
    int empId;      
    struct employee *next;  
} emp;

emp* createnode(emp* head, char name[10], int empId) {
    emp* newnode = (emp*)malloc(sizeof(emp));
    newnode->empId = empId;
    strncpy(newnode->name, name, sizeof(newnode->name) - 1);
    newnode->next = NULL;

    
    if (head == NULL) {
        return newnode;
    }

    
    emp* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    
    return head;  
}


emp* findmid(emp* start, emp* end) {
    if (start == NULL) return NULL;
    emp* slow = start;
    emp* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

void binary_search(emp* start, emp* end, int empId) {
    if (start == NULL || start == end) {
        return;
    }

    emp* middle = findmid(start, end);

    if (middle->empId == empId) {
        printf("\nEmployee ID %d is %s\n", empId, middle->name);
        return;
    }

    
    if (middle->empId > empId) {
        end = middle;
        binary_search(start, end, empId);
    }
    
    else {
        start = middle->next;
        binary_search(start, end, empId);
    }
}

void display(emp* head) {
    emp* temp = head;
    while (temp != NULL) {
        printf("Employee ID: %d, Name: %s\n", temp->empId, temp->name);
        temp = temp->next;
    }
}

int main() {
    int input_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    char names[10][10] = {"Ankit","Sanket","yash" ,"Vivek", "Ankit", "Chandan", "Riya", "Dhanush","Ash","kumar"};

    emp* head = NULL;  

    for (int itr = 0; itr < size; itr++) {
        head = createnode(head, names[itr], input_array[itr]);
    }

    printf("Employee list:\n");
    display(head);

    int searchEmpId ;
    printf("Enter the emp Id \n");
    scanf("%d",&searchEmpId);
    binary_search(head, NULL, searchEmpId);

    return 0;
}
