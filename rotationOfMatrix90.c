#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *num1,int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void transpose(int** matrix,int matSize){

    for(int i=0;i<matSize;i++){

        for(int j=i;j<matSize;j++){

            if(i == j)continue;
            
            swap( *(matrix+i)+j, (*(matrix+j)+i ));
        }
    }
}

void reverseArray(int **matrix,int matrixSize){
     for(int i=0;i<matrixSize;i++){

        int low = 0, high = matrixSize-1;
        
        while(low<high){
            swap( *(matrix+i)+low, *(matrix+i)+high  );
            low++;
            high--;
        }
    }
}

void rotate(int** matrix, int matrixSize) {
    
    transpose(matrix,matrixSize);
    reverseArray(matrix,matrixSize);
    
}


int main(){

    int size;
    printf("Enter the size of Matrix : ");
    scanf("%d",&size);

    int** matrix = (int **)malloc(size * sizeof(int));
    
    for(int i=0;i<size;i++){
        matrix[i] = (int *)malloc(size * sizeof(int));
        for(int j=0;j<size;j++){
            scanf("%d",(*(matrix+i)+j));
        }
    }

    rotate(matrix,size);
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }

    for(int i=0;i<size;i++){
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}