#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    int n;
    scanf("%d",&n);

    char name[40];
    //'\n' in buffer so fgets dont work
    //getchar();
    // fgets(name,49,stdin);
    // printf("%s",name);

    //doesnot need getchar it ignores it 
     printf(" enter a string :\n");
     scanf(" %[^\n]",name);
     printf("%s\n",name);
    printf("%d\n",strlen(name));

    char hu;
    printf(" enter char :");
    scanf("%c",&hu);
    printf("%c\n",hu);

    printf(" enter a string :\n");
    char *anotherName = (char *)malloc(50 *sizeof(char));
    scanf(" %[^\n]",anotherName);
     printf("%s\n",anotherName);
    printf("%d\n",strlen(anotherName));

    //similary way

    //" "skip whitespace including newlilnes ,spaces or tabs
    // read until \n and donot include \name
    //*c reads exactly one character, even if its a new line or whitespace
    //* before c is a suppression operator, which tells scanf to read the character but not store it
   
    char string[50];
    printf(" enter a string :\n");
    scanf(" %[^\n]%*c",string);
    printf("%s\n",string);
    printf("%d\n",strlen(string));

    getchar();
    char ch;
    printf(" enter a character :\n");
    scanf("%c",&ch);
    printf("%c\n",ch);

    char string1[50];
    printf(" enter a string :\n");
    scanf(" %[^\n]*c",string1);
    printf("%s\n",string1);
    printf("%d\n",strlen(string1));

    return 0;
}