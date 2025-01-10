#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main() {
    int numbers[10]; // Array to store integers
    int count = 0;   // Number of integers scanned
    char input[100]; // Buffer to store the input as a string

    printf("Enter input (format: 1,2,3,...): ");
    scanf("%99s", input); // Read the entire line as a string

    char *token = strtok(input, ",");
    
    while (token != NULL && count < 10) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    printf("Numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
