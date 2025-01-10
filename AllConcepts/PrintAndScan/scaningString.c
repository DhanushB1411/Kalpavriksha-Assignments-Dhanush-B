#include<stdio.h>
#include<string.h>

int main(){
    char name[50];
    printf("Enter name:");
    scanf("%s",name); //scan only upto 49 characters
    printf("%s\n",name);
    
    //after space it puts '\0' null character
    int i=0;
    while(name[i] !='\0'){
        printf("%c",name[i]);
        i++;
    }

    printf("\nsize : %d\n",i);


    /*char fname[30],lastname[30];    
    printf("\nenter name: \n");

    scanf("%s%s",fname,lastname);
    printf("%s %s\n",fname,lastname);
    */
    getchar();
   
    
    char fullname[50];
    
    printf("Enter full name: \n");

    fgets(fullname,49,stdin);

    puts(fullname);

    i=0;

    while(fullname[i] !='\0'){
        printf("%d(%d) -> %c\n",i,fullname[i],fullname[i]);
        i++;
    }
    printf("size : %d\n",i);
    //at 7 has new line character
    //need to remove that replace it with '\0'

    char othername[50];
    printf("Enter name:\n");
    //scanf("%s",othername);
    fgets(othername,49,stdin);

    puts(fullname);

    i=0;

    while(fullname[i] !='\0'){
        printf("%d(%d) -> %c\n",i,fullname[i],fullname[i]);
        i++;

    }
    printf("%d",strlen(fullname));
    // so at '\n' -> '\0'
    printf("size : %d\n",i);
    if(i>0 && fullname[i-1] == '\n')
        fullname[i-1] = '\0';

    printf("After replacing \n");
    printf("%d",strlen(fullname));



    
}
