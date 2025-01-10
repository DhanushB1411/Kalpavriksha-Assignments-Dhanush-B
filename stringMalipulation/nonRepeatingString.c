#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void nonRepeatinCharString(char *input,char *outputString){
     int hassh[100]={0};

    int newStringSize=0;

    int iteratorI=0;
    while(input[iteratorI] != '\0'){

        if(hassh[input[iteratorI]-'a'] == 0){
            outputString[newStringSize++]= input[iteratorI];
        }

        hassh[input[iteratorI] -'a']++;
        iteratorI++;

    }

    outputString[newStringSize] = '\0';
    
}





int main(){

    char input[100];
    printf("Enter input :");
    scanf("%s",input);

    char outputString[100];

    nonRepeatinCharString(input,outputString);
    printf("%s\n",outputString);


}