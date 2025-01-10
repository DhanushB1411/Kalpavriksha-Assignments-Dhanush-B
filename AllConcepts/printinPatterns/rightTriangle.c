#include<stdio.h>

int main(){

    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            printf("* ");
        }

        printf("\n");
    }
   
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(j>5-i){
                printf("*");
                continue;
            }
            printf(" ");
        }
        printf("\n");
    }

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            printf(" ");
            if(j>5-i){
                printf("*");
                continue;
            }
        }
        printf("\n");
    }

    printf("\n");
    for(int i=1;i<=5;i++){

        for(int s =1 ;s<=(5-i);s++){
            printf(" ");
        }

        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }

    for(int i=1;i<=5;i++){

        for(int j=1;j<=5-i;j++){
            printf(" ");
        }

       for(int k = 1;k<=(2*i)-1;k++)
            printf("*");
        
        printf("\n");
    }

    printf("\n");
    for(int i=1;i<=5;i++){

        for(int j=1;j<=(5-(5-i))-1;j++){
            printf(" ");
        }

       for(int k = 1;k<=2*(5-i)+1;k++)
            printf("*");
        
        printf("\n");
    }

    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=4;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }   
}