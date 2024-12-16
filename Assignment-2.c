#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct User
{
    int Id;
    char Name[50];
    int Age;
} User;

void addUser();
void displayUsers();
void updateUser();
void deleteUser();
int checkUserExists(int id); 
User getInputUserDetails();  
void printUserDetails(User user); 

int main()
{
    int choice;

    while (1)
    {
        printf("\n__________________ User Management System ______________________\n\n");
        printf("1. Add New User\n2. Display All Users\n3. Update User\n4. Delete User\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("\nExiting... Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addUser()
{
    FILE *file = fopen("user.txt", "a+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    User newUser = getInputUserDetails();

    if (checkUserExists(newUser.Id))
    {
        printf("User ID %d already exists! Cannot add duplicate.\n", newUser.Id);
        fclose(file);
        return;
    }

    fprintf(file, "%d,%s,%d\n", newUser.Id, newUser.Name, newUser.Age);
    fclose(file);
    printf("New user added successfully.\n");
}

void displayUsers()
{
    FILE *file = fopen("user.txt", "r");
    if (file == NULL)
    {
        printf("No users found!\n");
        return;
    }

    User user;
    printf("\nList of Users:\n");
    printf("ID\t\tName\t\tAge\n");

    while (fscanf(file, "%d,%[^,],%d\n", &user.Id, user.Name, &user.Age) != EOF)
    {
        printUserDetails(user);
    }

    fclose(file);
}

void updateUser()
{
    int id, isFound = 0;
    printf("\nEnter the ID to update: ");
    scanf("%d", &id);

    FILE *file = fopen("user.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    User user;
    while (fscanf(file, "%d,%[^,],%d\n", &user.Id, user.Name, &user.Age) != EOF)
    {
        if (user.Id == id)
        {
            isFound = 1;
            printf("Enter updated details:\n");
            User updatedUser = getInputUserDetails();
            updatedUser.Id = id; 
            fprintf(tempFile, "%d,%s,%d\n", updatedUser.Id, updatedUser.Name, updatedUser.Age);
        }
        else
        {
            fprintf(tempFile, "%d,%s,%d\n", user.Id, user.Name, user.Age);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (isFound)
    {
        printf("User updated successfully.\n");
    }
    else
    {
        printf("User with ID %d not found!\n", id);
    }
}

void deleteUser()
{
    int id, isFound = 0;
    printf("\nEnter the ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen("user.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    User user;
    while (fscanf(file, "%d,%[^,],%d\n", &user.Id, user.Name, &user.Age) != EOF)
    {
        if (user.Id == id)
        {
            isFound = 1;
            continue; // Skip writing this user to delete them
        }
        fprintf(tempFile, "%d,%s,%d\n", user.Id, user.Name, user.Age);
    }

    fclose(file);
    fclose(tempFile);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (isFound)
    {
        printf("User deleted successfully.\n");
    }
    else
    {
        printf("User with ID %d not found!\n", id);
    }
}

int checkUserExists(int id)
{
    FILE *file = fopen("user.txt", "r");
    if (file == NULL)
    {
        return 0; 
    }

    User user;
    while (fscanf(file, "%d,%[^,],%d\n", &user.Id, user.Name, &user.Age) != EOF)
    {
        if (user.Id == id)
        {
            fclose(file);
            return 1; // User ID already exists
        }
    }

    fclose(file);
    return 0; 
}

User getInputUserDetails()
{
    User user;

    printf("User ID: ");
    scanf("%d", &user.Id);

    printf("User Name: ");
    scanf(" %[^\n]", user.Name);

    printf("User Age: ");
    scanf("%d", &user.Age);

    return user;
}

// Function to print user details
void printUserDetails(User user)
{
    printf("%d\t\t%s\t\t%d\n", user.Id, user.Name, user.Age);
}
