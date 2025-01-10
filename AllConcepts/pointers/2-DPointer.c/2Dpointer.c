#include<stdio.h>
#include<stdlib.h>

int main(){

    int arr[][4] = { {11,22,33,44},
                    {55,66,77,88},
                    {11,66,77,44}};


    printf("arr -> %p\n arr+1 -> %p\n",arr, arr+1);
    printf("**arr ->%d \n **(arr+1)->%d\n",**arr,**(arr+1));
    printf("*arr -> %p\n (*arr)+1-> %p\n",*arr, (*arr)+1);
    printf("**arr -> %d\n *((*arr)+1)-> %d\n",**arr, *((*arr)+1));
    
    printf("*(*arr+1) -> *(*(arr)+1) %d\n", *(*arr+1));

    //arr arr+1 will be the pointer to whole array
    //*arr will be pointer to int a single array
    
    //printf("%d",*arr);
}