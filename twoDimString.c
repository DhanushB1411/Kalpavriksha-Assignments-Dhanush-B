#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isVowel(char character);

void copyString(char *destination, const char *source);

void printTotalVowelsAndLongestName(char *names[10][101], int rowCount, int columnCount);

int stringLenght(char *string);

int main()
{
    int rowCount, columnCount;
    printf("Enter number of rows: ");
    scanf("%d", &rowCount);
    printf("Enter number of columns: ");
    scanf("%d", &columnCount);

    char *names[10][101];

    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            names[iteratorI][iteratorJ] = (char *)malloc(51 * sizeof(char));
            printf("Name at (%d,%d): ", iteratorI, iteratorJ);
            scanf(" %[^\n]", *(*(names + iteratorI) + iteratorJ));
        }
    }

    printf("\nNames Matrix:\n");
    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            printf("%s ", *(*(names + iteratorI) + iteratorJ));
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
    // converting lower to upper
    if (character >= 'a' && character <= 'z')
    {
        character = character - ('a' - 'A'); // character -36
    }
    return (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U');
}

void copyString(char *destinationString, const char *sourceString)
{
    while (*sourceString != '\0')
    {
        *destinationString = *sourceString;
        destinationString++;
        sourceString++;
    }
    *destinationString = '\0';
}

void printTotalVowelsAndLongestName(char *names[10][101], int rowCount, int columnCount)
{
    int vowelCount = 0;
    int maxLength = 0;
    char *longestName = (char *)malloc(51 * sizeof(char));

    for (int iteratorI = 0; iteratorI < rowCount; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < columnCount; iteratorJ++)
        {
            if (isVowel(*(*(*(names + iteratorI) + iteratorJ))))
            {
                vowelCount++;
            }

            int currentLength = stringLenght(*(*(names + iteratorI) + iteratorJ));

            if (maxLength < currentLength)
            {
                maxLength = currentLength;
                copyString(longestName, *(*(names + iteratorI) + iteratorJ));
            }
        }
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    free(longestName);
}

int stringLenght(char *string)
{
    int count = 0;
    while (*string)
    {
        count++;
        string++;
    }
    return count;
}
