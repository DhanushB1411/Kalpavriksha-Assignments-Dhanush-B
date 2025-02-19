#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack
{
    char array[1000];
    int top;
}Stack;


char peak(Stack *st)
{

    return(st->array[st->top]);
}
char pop(Stack *st)
{
    char ans = st->array[st->top];
    st->top = st->top-1;
    return ans;
}

void push(Stack *st,char data)
{
    st->top = st->top +1;
    st->array[st->top] =data;
    return;
}

void display(Stack *st)
{
    for(int i=0;i<=st->top;i++)
    {
        printf("%c",st->array[i]);
    }
    printf("\n");
}

bool isEmpty(Stack *st)
{
    if(st->top <0)return true;
    return false;
}
int main()
{
    char input[100];
    printf("Enter exp: ");
    scanf(" %[^\n]",input);
    //printf("%s\n",input);
    int size = strlen(input);
    Stack st;
    st.top =-1;

    for(int i=0;i<size;i++)
    {
        if(input[i] ==']')
        {

            int curSize=0; 
            char *sstr=NULL;

            while(peak(&st) !='[')
            {
                sstr= (char *)realloc(sstr,(curSize+1)*sizeof(char));

                sstr[curSize] = pop(&st);
                //printf("while in : %c\n",sstr[curSize]);
                curSize++;
            } 
            sstr[curSize] = '\0';
           // printf("string : %s\n",sstr);
            pop(&st);
          //  printf("stack :%c\n",peak(&st));
            if(isEmpty(&st)){
                for(int i=curSize-1;i>=0;i--)
                {
                    push(&st,sstr[i]);
                   // printf("inside st: %c ",peak(&st));
                }
                //printf("entered");
                break;
            }
            char num = peak(&st);
            int notimes =1;
            
            if(num>='0' && num<='9')
            {
                notimes = pop(&st)-'0';
            }


            //int notimes = pop(&st)-'0';
            printf("no Times : %d\n",notimes);
            for(int i=0;i<notimes;i++)
            {
                for(int j=curSize-1;j>=0;j--){
                    printf("pushing : %c\n",sstr[j]);
                    push(&st,sstr[j]);
            }

            }
            display(&st);
            
        }
        else
        {
           // printf("c: %c \n",input[i]);
            push(&st,input[i]);
        }
    }

    display(&st);

    return 0;
}