#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    printf("Enter : ");

    char input[100];
    scanf("%s",input);
    int size = strlen(input);
    int number =0;
    bool negative =false;

    int i=0;

    while(input[i]!='\0'){

        if(input[i] ==' '){
            i++;
            continue;
        }

        if(input[i] == '-'){
            if(number ==0)
                negative = true;
            else
                break;
            i++;
            continue;
        }

        if(input[i]>='0' && input[i]<='9'){
            number = number*10 + input[i] -'0';
        }else{
            break;
        }

        i++;

    }

    if(i != size){
        printf("%d",0);
    }else{
        if(negative){
            number = number*-1;
        }
        printf("%d",number);
    }
}