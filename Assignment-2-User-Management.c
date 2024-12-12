#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defining the struct to store the details of the user
struct user
{
    int id;
    char name[50];
    int age;
};

void main()
{

    int ch;

    while (1)
    {
        printf(" \n__________________User Management System______________________     \n\n");

        printf(" 1. Add new User \n 2. Display all users\n");
        printf(" 3. Update user  \n 4. Delete User\n 5. Exit\n");

        printf("\nEnter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:  // to create new user
        {
            struct user newuser;

            printf("\nUser ID :");
            scanf("%d", &newuser.id);

            printf("User Name:");
            scanf(" %[^\n]", newuser.name);

            printf("User Age : ");
            scanf("%d", &newuser.age);

            FILE *fp = NULL;
            fp = fopen("user.txt", "a");

            if (fp == NULL)
            {
                printf(" FILE NAME ALREADY EXISTS ! ");
                break;
            }

            fprintf(fp, "%d,%s,%d\n", newuser.id, newuser.name, newuser.age);
            fclose(fp);
            printf("New user added \n");
            break;
        }
        case 2: // to display users
        {
            FILE *fptr = fopen("user.txt", "r");

            if (fptr == NULL)
            {
                printf("NO USER FOUND!\n");
                break;
            }

            char str[100];
            while (fgets(str, sizeof(str), fptr) != NULL)
            {   
                printf("%s", str);
            }

            fclose(fptr);
            break;
        }

        case 3:  // to update users
        {
            int id, flag = 0;
            printf("\nEnter the ID to update: ");
            scanf("%d", &id);

            FILE *file1 = fopen("user.txt", "r");  // for reading
            FILE *writeFile = fopen("temp.txt", "w"); // for writing

            if (file1 == NULL || writeFile == NULL)
            {
                printf("\n NO USER FOUND !\n");
                break;
            }

            struct user newuser;
            while (fscanf(file1, "%d,%[^,],%d\n", &newuser.id, newuser.name, &newuser.age) != EOF)
            {
                if (newuser.id == id)
                {
                    flag = 1;
                    printf("Enter Updated Name: ");
                    scanf(" %[^\n]", newuser.name);
                    printf("Enter New Age: ");
                    scanf("%d", &newuser.age);
                }
                fprintf(writeFile, "%d,%s,%d\n", newuser.id, newuser.name, newuser.age);
            }

            fclose(file1);
            fclose(writeFile);

            remove("user.txt");
            rename("temp.txt", "user.txt");

            if (flag)
            {
                printf("User updated successfully.\n");
            }
            else
            {
                printf(" USER NOT FOUND \n");
            }
            break;
        }

        case 4:
        {
            // to delete the users
            int id, flag = 0;
            printf("Enter the ID to delete: ");
            scanf("%d", &id);

            FILE *file = fopen("user.txt", "r"); 
            FILE *tempFile = fopen("temp.txt", "w");

            if (file == NULL || tempFile == NULL)
            {
                printf("PROBLEM IN OPENING THE FILE\n");
                break;
            }

            struct user newuser;
            while (fscanf(file, "%d,%[^,],%d\n", &newuser.id, newuser.name, &newuser.age) != EOF)
            {
                if (newuser.id == id)
                {
                    flag = 1;
                    continue;
                }
                fprintf(tempFile, "%d,%s,%d\n", newuser.id, newuser.name, newuser.age);
            }

            fclose(file);
            fclose(tempFile);

            remove("user.txt");
            rename("temp.txt", "user.txt");

            if (flag)
            {
                printf("User deleted successfully.\n");
            }
            else
            {
                printf("USER NOT FOUND !\n");
            }
            break;
        }

        case 5: // exiting the program
            printf("\nExiting \nThank YOU");
            exit(0);

        default:
            printf(" wrong choice . Try again");
        }
    }
}