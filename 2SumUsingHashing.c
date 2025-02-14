#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HashSize 10000

typedef struct {
    int value;
    int index;
}HashNode;

HashNode* hash[HashSize] ;

int hashFun(int value){
    return abs(value)%HashSize;
}


void insert(int value,int index){
    
    int idx = hashFun(value);
    while(hash[idx]!=NULL)
        idx = (idx+1)%HashSize;

    HashNode* newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->value = value;
    newNode->index = index;
    hash[idx] = newNode;
}

int find(int value){
    int idx = hashFun(value);
    while (hash[idx]!=NULL)
    {
       if(hash[idx]->value == value){
        return hash[idx]->index;
       }
       idx = (idx+1)%HashSize;
    }
    
    return -1;
}

int *twoSum(int *nums,int numsSizes,int target,int *returnSize){

    int* ans =(int *)malloc(2*sizeof(int));
    *returnSize =2;

    for(int i=0;i<numsSizes;i++){

        int rem = target-nums[i];
    
        if(find(rem) == -1){
            insert(nums[i],i);
        }else{
            ans[0] = find(rem);
            ans[1] = i;
            return ans;
        }
    }
    return ans;
}

void initializeHashTable(){
    for(int i=0;i<HashSize;i++){
        hash[i] =NULL;
    }
}
int main(){

    int nums[] = {0,4,3,0};
    int numsSize =sizeof(nums)/sizeof(nums[0]);

    int target = 0;
    int returnSize=0;

    initializeHashTable();

    int *ans = twoSum(nums,numsSize,target,&returnSize);

    for(int i=0;i<returnSize;i++){
        printf("%d ",ans[i]);
    }
    
    free(ans);
    return 0;
}