#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Test{
    int a;
    char str[20];
}test;


int main(){
    test t1,t2;

    strcpy(t1.str,"Learn&code");
    t2 = t1;
    
    t1.str[0] = 'S';

    printf("%s\n",t1.str);
    printf("%s\n",t2.str);

    test *pt1;
    pt1 = (struct Test *)malloc(sizeof(struct Test));
    
    strcpy(pt1->str,"hello ");
    printf("pt1-> str : %s",pt1->str);

    struct Test *pt2;
    pt2 = (struct Test *)malloc(sizeof(struct Test));
    pt2 = pt1;

    pt2->str[0] = 'P';

    printf("pt1->str :%s",pt1->str);


}