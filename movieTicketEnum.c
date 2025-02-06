#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 10
 
// Define an enum to represent booking status
enum bookingStatus {
    PENDING,
    APPROVED,
    BOOKED
};
 
struct node {
    char movie[100];
    int screen;
    int seat;
    int amount;
    enum bookingStatus status;
    struct node* next;
};
 
struct node* pendingBookings = NULL;
struct node* approvedBookings = NULL;
 
struct node* createNode(char* movie, int screen, int seat, int amt) {
    printf("Node creation started\n");
    struct node* newNode = malloc(sizeof(struct node));
    newNode->screen = screen;
    newNode->amount = amt;
    newNode->seat = seat;
    strcpy(newNode->movie, movie);
    newNode->status = PENDING;  // Initial status is PENDING
    newNode->next = NULL;
    printf("Node created\n");
    return newNode;
}
 
void enqueue(struct node** head, struct node* newNode) {
    struct node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
 
void book(struct node* head) {
    int screen, seat, amt;
    char movie[100];
    printf("Enter movie name:\n");
    getchar();
    scanf("%[^\n]s", movie);
    printf("Enter screen\n");
    scanf("%d", &screen);
    printf("Enter seatNo\n");
    scanf("%d", &seat);
    printf("Enter amount\n");
    scanf("%d", &amt);
    struct node* newNode = createNode(movie, screen, seat, amt);
    enqueue(&pendingBookings, newNode);
    printf("Booking done\n");
}
 
struct node* dequeue(struct node** head) {
    struct node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    return temp;
}
 
void approve(struct node** head1, struct node** head2) {
    if (*head1 == NULL) {
        printf("No bookings left\n");
        return;
    }
    struct node* booked = dequeue(head1);
    booked->status = APPROVED;  // Update status to APPROVED when moved
    enqueue(head2, booked);
    printf("Booking approved\n");
}
 
void display(struct node** head, int type) {
    if (type == 1) {
        printf("Pending bookings to be approved:\n");
    } else {
        printf("Approved bookings:\n");
    }
    struct node* temp = *head;
    if (temp == NULL) {
        printf("No bookings to display.\n");
    } else {
        while (temp != NULL) {
            const char* statusStr = (temp->status == PENDING) ? "PENDING" :
                                    (temp->status == APPROVED) ? "APPROVED" : "BOOKED";
            printf("Movie: %s, Screen: %d, Seat Number: %d, Amount: %d, Status: %s\n",
                   temp->movie, temp->screen, temp->seat, temp->amount, statusStr);
            temp = temp->next;
        }
    }
    printf("End of display\n");
}
 
int main() {
    while (1) {
        printf("\nEnter your choice: \n");
        printf("1. Book\n");
        printf("2. Approve\n");
        printf("3. Pending Bookings\n");
        printf("4. Approved Bookings\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                book(pendingBookings);
                break;
            case 2:
                approve(&pendingBookings, &approvedBookings);
                break;
            case 3:
                display(&pendingBookings, 1);
                break;
            case 4:
                display(&approvedBookings, 2);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid operation! Please enter a valid choice.\n");
                break;
        }
    }
}