#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *longestStringFun(char* str){
    int maxLen, wordLen =0;
    char word[100];
    char *longestWord = (char *)malloc(50*sizeof(char));
    while(*str){
        if(*str != ' ' && *str !='\0'){
            word[wordLen++] = *str;
            str++;
        }
        else{
            word[wordLen] = '\0';
            if(wordLen>=maxLen){
                maxLen = wordLen;
                strcpy(longestWord,word);
            }

            wordLen =0;
             if (*str == '\0')
                break;

            str++;
        }

        if(*str == '\0'){
            word[wordLen] = '\0';
            if(wordLen>maxLen){
                maxLen = wordLen;
                strcpy(longestWord,word);
            }

        }

    }

    printf("%s\n",longestWord);
    return longestWord;
}


int main(){

    char str[100];
    printf("Enter :");
    scanf(" %[^\n]%*c",str);

   int maxi=0;
   char *longestString;
    char *token = strtok(str," ");
    while(token !=NULL){
        if(strlen(token)>=maxi){
            maxi = strlen(token);
            longestString = token;
        }
        token = strtok(NULL, " ");
    }

    printf("%s\n",longestString);

    char str2[100];
    printf("Enter :");
    scanf(" %[^\n]%*c",str2);
    
    char *longStr = longestStringFun(str2);
    printf("%s\n",longStr);
    free(longStr);
}