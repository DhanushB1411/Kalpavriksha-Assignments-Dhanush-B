#include<stdio.h>
int main() {  
     int num;     
    char inputs[5][100]; 
    int itr = 0;
    while (itr < 5 && scanf(" %[^;]%*c", inputs[itr]) == 1) {
     itr++;
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("%s\n",inputs[i]);
    }
    return 0; 
}  
