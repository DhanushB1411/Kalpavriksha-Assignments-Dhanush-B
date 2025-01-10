#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void stringCnt(char *str1, char *str2,char *newStr){

    while(*str1){
        *newStr = *str1;
        newStr++;
        str1++;
    }

    while(*str2){
        *newStr = *str2;
        newStr++;
        str2++;
    }

   /// return newStr;

}

char *stringCnt2(char *str1, char *str2){
    char *newStr1 = (char *)malloc(20*sizeof(char));
    char *ptr = newStr1;

    while(*str1){
        *ptr = *str1;
        ptr++;
        str1++;
    }

    while(*str2){
        *ptr = *str2;
        ptr++;
        str2++;
    }
    *ptr = '\0';
    printf("%s\n",newStr1);
    return newStr1;

}




int main(){

    char str1[] = "hello";
    char str2[] = "Word";

    char *newStr = (char *)malloc(20* sizeof(char));
    stringCnt(str1,str2,newStr);

    printf("%s\n",newStr);
    free(newStr);

    printf("%s \t %d\n",str1,strcat(str1,str2));

    char *newStr2 = stringCnt2(str1, str2);
    if (newStr2) {
        printf("Concatenated String: %s\n", newStr2);
        free(newStr2); // Free allocated memory
    }

}