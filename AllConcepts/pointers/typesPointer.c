#include<stdio.h>
#include<stdlib.h>

void printing(){
    printf(" hello hii \n");
}

int main(){

    int x =10;
    float y = 5.5;

    void *ptr;
    ptr = &x;
    printf("Value of x : %d\n",*(int *)ptr);
    ptr = &y;
    printf("Value of y : %.2f\n", *(float *)ptr);

    int *ptr2;
    ptr2 = (int *)malloc(sizeof(int));
   
   *ptr2 = 7;
    printf("%d\n",*ptr2);

    void (*ptrFun)() = printing;
    ptrFun();


}