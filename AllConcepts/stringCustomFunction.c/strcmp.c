#include<stdio.h>
#include<string.h>

int cust_strcmp(char *str1, char *str2){
    int flag =0,i;
    for(i=0;str1[i]!='\0' || str2[i] !='\0';i++){
        if(str1[i] != str2[i]){
           flag =1;
           break;
        }
    }

    if(str1[i]>str2[i]){
        return 1;
    }else{
        return -1;
    }

    return 0;
}

int main(){
    printf("%d\n",cust_strcmp("A","ACZ"));
    printf("%d\n",strcmp("A","ACZ"));

    return 0;
}