#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100
 
typedef struct Record
{
    char key[30];
    int value;
    struct Record *next;
} Record;
 
typedef struct HashTable
{
    Record *buckets[SIZE];
} HashTable;
 
int computeHash(char *str)
{
    unsigned long hash = 5381;
    int character;
    while ((character = *str++))
        hash = ((hash << 5) + hash) + character;
    return hash % SIZE;
}
 
void addRecord(HashTable *table, char *key, int value)
{
    int index = computeHash(key);
    Record *current = table->buckets[index];
 
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            printf("Success\n");
            return;
        }
        current = current->next;
    }
 
    Record *newRecord = (Record *)malloc(sizeof(Record));
    strcpy(newRecord->key, key);
    newRecord->value = value;
    newRecord->next = table->buckets[index];
    table->buckets[index] = newRecord;
 
    printf("Success\n");
}
 
void findRecord(HashTable *table, char *key)
{
    int index = computeHash(key);
    Record *current = table->buckets[index];
 
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            printf("%d\n", current->value);
            return;
        }
        current = current->next;
    }
    printf("Not Found\n");
}
 
void removeRecord(HashTable *table, char *key)
{
    int index = computeHash(key);
    Record *current = table->buckets[index];
    Record *prev = NULL;
 
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev == NULL)
            {
                table->buckets[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            printf("Success\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Not Found\n");
}
 
int main()
{
    int count;
    scanf("%d\n", &count);
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
 
    for (int index = 0; index < count; index++)
    {
        table->buckets[index] = NULL;
    }
 
    for (int index = 0; index < count; index++)
    {
        char input[100];
        fgets(input, sizeof(input), stdin);
 
        char key[20];
        int value;
        if (sscanf(input, " add(\"%19[^\"]\", %d) ", key, &value) == 2)
        {
            addRecord(table, key, value);
        }
 
        else if (sscanf(input, " search(\"%19[^\"]\") ", key) == 1)
        {
            findRecord(table, key);
        }
 
        else if (sscanf(input, " delete(\"%19[^\"]\") ", key) == 1)
        {
            removeRecord(table, key);
        }
    }
    return 0;
}