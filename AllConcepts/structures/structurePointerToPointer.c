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
  
    emp **empP = (emp **)malloc(2 * sizeof(emp *));
    for(int i=0;i<2;i++){
        *(empP+i) = (emp *)malloc(sizeof(emp));

        empP[i]->num = 21+i;
        printf("Enter names : ");
        scanf(" %[^\n]%*c",empP[i]->name);

        printf("Enter date-month-year :\n");
        scanf("%d",&empP[i]->doj.day);
        scanf("%s",empP[i]->doj.month);
        scanf("%d",&empP[i]->doj.year);

    }

    printf("\nEmployee Details:\n");
    for (int i = 0; i < 2; i++) {
        printf("Rnum: %d\n", empP[i]->num);
        printf("Name: %s\n", empP[i]->name);
        printf("Date of Joining: %02d-%s-%d\n\n", empP[i]->doj.day, empP[i]->doj.month, empP[i]->doj.year);
        free(empP[i]); 
    }
    free(empP);
    return 0;
}