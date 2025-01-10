#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct doj{
    int day;
    char month[10];
    int year;
}Doj;

typedef struct employee{
    int num;
    char name[50];
    Doj doj;
}emp;
 

int main(){
    emp e1[3];

    for(int i=0;i<3;i++){
    printf("Enter details for employee %d:\n", i + 1);
   
    printf("Name: ");
    
    scanf(" %[^\n]%*c",e1[i].name);

    printf("Employee ID: ");
    scanf("%d", &e1[i].num);

    printf("Day of Joining: ");
    scanf("%d", &e1[i].doj.day);
    
    printf("Month of Joining: ");
    getchar();
    fgets(e1[i].doj.month, sizeof(e1[i].doj.month),stdin);
    e1[i].doj.month[strcspn(e1[i].doj.month,"\n")] = '\0';

    printf(" Enter year : ");
    scanf("%d",&e1[i].doj.year);
    }

    printf("\nEntered Employee Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", e1[i].name);
        printf("ID: %d\n", e1[i].num);
        printf("Date of Joining: %02d-%s-%d\n", e1[i].doj.day, e1[i].doj.month, e1[i].doj.year);
        printf("\n");
    }
    
    return 0;
}