#include<stdio.h>
#include<stdlib.h>

int *countDistitElementInArrayK(int *arr,int k,int *size,int arrSize){

    int left =0;
    int right =0;

    int count=0;
    int frequency[1000]={0};
    int distinct=0;

    int *ans =NULL;

    while (right<k)
    {

        if(frequency[arr[right]]==0){
            distinct++;
            count++;
        }
        frequency[arr[right]]++;  
        
        right++;
    }
    ans = (int *)malloc( ((*size)+1) *sizeof(int));
    ans[*size] = count;
    printf("cnt :%d \n",count);
    *size = *size +1;

    while (right<arrSize){
        left++;
        frequency[arr[left]]--;
        if(frequency[arr[left]] == 0){
            distinct--;
            count--;
        }
        right++;
        if(frequency[arr[right]]==0){
            distinct++;
            count++;
        }
        frequency[arr[right]]++;

        ans = (int *)realloc(ans,((*size)+1) *sizeof(int));
        ans[*size] = count;
        printf(" %d ",ans[*size]);
        *size = *size +1;
    }
    
}

int main(){
    int arr[] = {1,2,1,3,4,2,3};
    int k =4;
    int size =0;
    int arrSize =sizeof(arr)/sizeof(arr[0]);
    int *ans = countDistitElementInArrayK(arr,k,&size,arrSize);

    printf("[");
    for(int i=0;i<size;i++){
        if(i==0){
            printf("%d",arr[i]);
        }
        printf(", %d",arr[i]);
    }printf("]\n");

    return 0;
}