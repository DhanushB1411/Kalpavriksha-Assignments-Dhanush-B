#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    printf("Enter row and col: ");
    scanf("%d%d", &row, &col);

    char ***strings = (char ***)malloc(row * sizeof(char **));

    for (int i = 0; i < row; i++) {
        strings[i] = (char **)malloc(col * sizeof(char *));
        for (int j = 0; j < col; j++) {
            strings[i][j] = (char *)malloc(50 * sizeof(char)); // Assuming max length of string is 50
            printf("Enter string for row %d, col %d: ", i + 1, j + 1);
            scanf(" %[^\n]%*c", strings[i][j]);
        }
    }

    
    printf("\nEntered Strings:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s\t", strings[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            free(strings[i][j]); 
        }
        free(strings[i]); 
    }
    free(strings); 

    return 0;
}
