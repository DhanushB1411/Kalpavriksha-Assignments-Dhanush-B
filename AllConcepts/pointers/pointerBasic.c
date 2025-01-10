#include<stdio.h>

int main(){

    int a = 3;

    int *ptr = &a;

    int **pPtr = &ptr;

    printf("ptr -> %p \n*ptr ->%d\n",ptr,*ptr);
    printf("&ptr->%p \n pPtr->%p\n *pPtr->%p\n **pPtr ->%d\n",&ptr,pPtr,*pPtr,**pPtr);

    
    

}