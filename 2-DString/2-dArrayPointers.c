#include <stdio.h>
#include<stdlib.h>

int main() {
    
    char *strings[10][10];
    
    int row,col;
    printf("Enter row and col :");
    scanf("%d%d",&row,&col);

    for(int i=0;i<row;i++){
        printf("Enter strings for 1st col : %d \n",i);
        for(int j=0;j<col;j++){
            printf("Enter %d of %d col \n",i,j);
            strings[i][j] = (char *)malloc(50* sizeof(char));
            scanf(" %[^\n]%*c", *(*(strings+i)+j) );
        }
    }

    
    printf("\n");
    printf("first letter of strings -> %c\n\n",***strings);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%s\t",*(*(strings+i)+j));
        }
        printf("\n");
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            free(strings[i][j]);
        }
    }
    return 0;
}