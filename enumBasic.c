#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum day {Sunday =0, Monday, Tuesday, Wednesday};

int main()
{

    printf("%d \n",Tuesday);

    enum day today = Tuesday;
    printf(" %d\n",today);

}