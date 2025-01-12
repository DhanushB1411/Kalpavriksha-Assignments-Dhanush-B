#include<stdio.h>
#include<stdbool.h>
#include<string.h>


bool checkAnagram(char *str1,char *str2){
   

    int stringHash[58] ={0};
    
    int string1Size = strlen(str1);
    
    int string2Size = strlen(str2);

    for(int i=0;i<string1Size;i++){
        stringHash[str1[i]-'A']++;
    }

    for(int i=0;i<=57;i++){
        printf("%d",stringHash[i]);
    }

    printf("\n");
    
    for(int i=0;i<string2Size;i++){
        stringHash[str2[i]-'A']--;
    }
    
    for(int i=0;i<=57;i++){
        printf("%d",stringHash[i]);
    }
    printf("\n");

    for(int i=0;i<=57;i++){
        if(stringHash[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    char string1[100];
    char string2[100];
    printf("'A' ->%d 'z'->%d 'z'-'A -> '%d\n",'A','z','z'-'A');
    printf("Enter the first string : ");
    scanf("%s",string1);

    printf("Enter the second string : ");
    scanf("%s",string2);

    if(checkAnagram(string1,string2)){
        printf("true\n");
    }else{
        printf("false\n");
    }

}