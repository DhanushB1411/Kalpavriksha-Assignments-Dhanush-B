#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool checkRoataion(char* string ,char *subString,int size,int curentInd){
    int i=0;
    for( i=0;i<size;i++){
        
        if(curentInd>=size){
            curentInd = curentInd%size;
        }

        if(string[curentInd++] !=subString[i]){
            break;
        }

    }

    if(i != size){
        return false;
    }
    return true;

    
}


int main(){

    char string1[100];
    char string2[100];

    printf("Enter String1 and String2 :\n");
    scanf(" %[^\n]%*c",string1);
    scanf(" %[^\n]%*c",string2);

    int size = strlen(string2);
    bool flag = true;
    for(int i=0;i<size;i++){
        if(checkRoataion(string1,string2,size,i) ==true){
            printf("true\n");
            flag = false;
            break;
        }
    }
    if(flag)
        printf("False\n");
    

}