#include<stdio.h>
#include<string.h>

void revStr(char *str){
    int i=0;
    int j= strlen(str);
    j = j-1;
    while(i<=j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(){
    char str[100];
    scanf(" %[^\n]%*c",str);

    printf("%s\n",str);

    revStr(str);

    printf("%s\n",str);

}