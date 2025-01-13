#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool checkPalindrom(char *startPointer ,char *endPointer){

    while(startPointer<=endPointer){
    
        if(*startPointer!=*endPointer)
            return false;
        startPointer++;
        endPointer--;
    }

    return true;
}

void stringCpy(char *desti,char *source, int size){
    
    for(int i=0;i<size;i++){
        *desti = *source;
        desti++;
        source++;
    }
    *desti='\0';
}

char *longestPalindrom(char *str){
    int size = strlen(str);
    int maxlen = 0;
      if (size == 1) {
        char *singleChar = (char *)malloc(2 * sizeof(char));
        singleChar[0] = str[0];
        singleChar[1] = '\0';
        return singleChar;
    }
    char *ans = (char *)malloc(size * sizeof(char));

    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int cur_size = ((str+j)-(str+i))+1;
           
            if(maxlen> cur_size)continue;
           
            if(checkPalindrom(str+i,str+j)){
           
              if(maxlen<=(cur_size)){
                        
                        stringCpy(ans,str+i,cur_size);
                        maxlen = cur_size;
                }
            }

        }
    }

    return ans;
}
int main(){

    char str[100];
    printf("Enter :");
    scanf(" %[^\n]%*c", str);

    char *ansString = longestPalindrom(str);

    printf("%s\n",ansString);

    free(ansString);
}