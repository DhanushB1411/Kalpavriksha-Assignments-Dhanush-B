#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char str[100];
    printf("Enter :");
    scanf(" %[^\n]%*c",str);

    return 0;
}