// C program to demonstrate the strtok() function
#include <stdio.h>
#include <string.h>

char* custom_strtok(char* str, const char* delimiters) {
    static char* nextToken = NULL; 
    if (str != NULL) {
        nextToken = str; 
    } else if (nextToken == NULL) {
        return NULL; // No more tokens
    }

    while (*nextToken && strchr(delimiters, *nextToken)) {
        nextToken++;
    }

    if (*nextToken == '\0') {
        nextToken = NULL;
        return NULL;
    }

    char* tokenStart = nextToken;

    while (*nextToken && !strchr(delimiters, *nextToken)) {
        nextToken++;
    }

    if (*nextToken) {
        *nextToken = '\0';
        nextToken++;
    } else {
        nextToken = NULL; // No more tokens
    }

    return tokenStart;
}


int main()
{
    char str[] = "Geeks,for.Geeks helo";
    
    const char delimiters[] = ",. ";

    char* token = strtok(str, delimiters);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiters);
    }
    

    char str2[] = "[[1 2 3],[4 5 6],[7 10 11]]";
    char* token1 = strtok(str2,"[, ]");
    
    while (token1 !=NULL)
    {
        printf("Token1 : %s\n",token1);
        token1 = strtok(NULL,"[, ]");
    }
    
    
    return 0;
}