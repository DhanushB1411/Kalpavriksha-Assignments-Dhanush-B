#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

int longestSubArray(int *arr, int n)
{

    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        int zero=0,one=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==0)zero++;
            else one++;
            
            if(zero == one){
                maxLen = maxLen<(j-i+1)?(j-i+1):maxLen;
            }
        }
    }
    
    return maxLen;
    
}


typedef struct node{
    int key;
    int value;
}Hash;

Hash hash[SIZE];

int hashFun(int key){
    return ((key%SIZE) +SIZE)%SIZE;
}

int longestSubArrayOp(int *arr, int n){
    
    int sum=0;

    for(int i=0;i<n;i++){
        
        if(*arr ==0){
            sum--;
        }else
        {
            sum++;
        }

        //if()
    }
    
}


int main(){

    int arr[] ={1,0,1,1,1,0,0};
    int size = sizeof(arr)/sizeof(int);

    printf("Ans : %d\n",longestSubArray(arr,size));

    return 0;
}