#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_words(char *ptr){
    
    int total_words =0;

    while(*ptr !='\0'){
        while(*ptr == ' '){ // to clear leading or ending space 
            ptr++;
        }

        if(*ptr =='\0'){
            break;
        }else{

            while(*ptr != ' ' && *ptr!='\0'){
                    printf("%c",*ptr);
                    ptr++;
            }
            printf("\n");
            total_words++;
        }


    }

    return total_words;

}

int main(){
    char *str = (char *)malloc(100 * sizeof(char));
    printf("Enter string : \n");
    scanf(" %[^\n]%*c",str);

    printf("\nTotal Words : %d\n",count_words(str));

    free(str);


    return 0;
}