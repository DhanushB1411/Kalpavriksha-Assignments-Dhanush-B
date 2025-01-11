#include <stdio.h>

int main() {
    char strings[100][100][100];

    int row,col;
    printf("Enter row and col :");
    scanf("%d%d",&row,&col);

    for(int i=0;i<row;i++){
        printf("Enter strings for 1st col : %d \n",i);
        for(int j=0;j<col;j++){
            printf("Enter %d of %d col \n",i,j);
            scanf(" %[^\n]%*c",strings[i][j]);
        }
    }

    printf("\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%s  ",strings[i][j]);
        }
        printf("\n");
    }

}