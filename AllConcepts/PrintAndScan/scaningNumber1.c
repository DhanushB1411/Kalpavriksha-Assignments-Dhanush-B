#include<stdio.h>

int main(){

    int numbers[10]; // Array to store integers
    int count = 0;   // Number of integers scanned
    char input[100]; // Buffer to store the input as a string

    printf("Enter input (format: 1,2,3,...): ");
    scanf("%99s", input); // Read the entire line as a string

    int i=0,cnt=0;
    int number =0;

    while(input[i]!='\0'){

        if(input[i] == ','){
            numbers[cnt++] = number;
            number =0;
        }
        if(input[i]>='0' && input[i]<='9'){
            number = number *10 + input[i]-'0';
        }
       i++;
    }

    if(number>0){
        numbers[cnt] = number;
    }


    for(int j=0;j<=cnt;j++){
        printf("%d ",numbers[j]);
    }
    printf("\n");
    return 0;
}