#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char character);
void copyString(char *destination, const char *source);
void printTotalVowelsAndLongestName(char *names[100][100], int rowCount, int columnCount);

int main()
{
    int rowCount, columnCount;
    printf("Enter number of rows: ");
    scanf("%d", &rowCount);
    printf("Enter number of columns: ");
    scanf("%d", &columnCount);

    char *names[100][100];

    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            names[iteratorI][iteratorJ] = (char *)malloc(51 * sizeof(char));
            printf("Name at (%d,%d): ", iteratorI, iteratorJ);
            scanf(" %[^\n]", names[iteratorI][iteratorJ]);
        }
    }

    printf("\nNames Matrix:\n");
    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            printf("%s ", names[iteratorI][iteratorJ]); 
        }
        printf("\n");
    }

    printTotalVowelsAndLongestName(names, rowCount, columnCount);

    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            free(names[iteratorI][iteratorJ]);
        }
    }

    return 0;
}

bool isVowel(char character)
{
    if (character >= 'a' && character <= 'z')
        character = character - ('a' - 'A');

    return (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U');
}

void copyString(char *destination, const char *source)
{
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

void printTotalVowelsAndLongestName(char *names[100][100], int rowCount, int columnCount)
{
    int vowelCount = 0;
    int maxLength = 0;
    char *longestName = (char *)malloc(51 * sizeof(char));

    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            if (isVowel(names[iteratorI][iteratorJ][0]))
            {
                vowelCount++;
            }

            int currentLength = strlen(names[iteratorI][iteratorJ]);

            if (maxLength < currentLength)
            {
                maxLength = currentLength;
                copyString(longestName, names[iteratorI][iteratorJ]);
            }
        }
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    free(longestName);
}
