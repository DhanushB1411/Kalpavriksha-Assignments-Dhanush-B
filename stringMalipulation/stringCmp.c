#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int stringCmp(char *str1, char *str2){

    while(*str2){
        if(*str1 == *str2){
            str1++;
            str2++;
        }else{
            return -1;
        }
    }
    return 0;
}

int main(){

    char str[] = "hello world";
    char substr[] = "world";
    bool flag = false;

    for(int i=0;i<strlen(str);i++){
        if(stringCmp(str+i,substr)==0){
            printf("%d\n",i+1);
            flag = true;
            break;
        }
    }

    if(!flag)
        printf("%d",-1);


    return 0;
}