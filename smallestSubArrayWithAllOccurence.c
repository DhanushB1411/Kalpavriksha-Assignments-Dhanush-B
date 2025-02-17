#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int startIdx;
    int endIdx;
    int freq ;
}Hash;

Hash hashTable[1000];

void smallestSubArrayWithAllOccurencesOfMostFreqEle(int *arr,int *startIdx, int *endIdx,int size){
    int maxFreq =0;

    for(int i=0;i<size;i++){
        if(hashTable[arr[i]].freq == 0){
            //printf("enterd : %d %d\n",hashTable[arr[i]].startIdx,i);
            hashTable[arr[i]].startIdx = i;
            //printf("enterd : %d %d\n",hashTable[arr[i]].startIdx,i);
            hashTable[arr[i]].endIdx =i;
            hashTable[arr[i]].freq++;
        }else
        {
            hashTable[arr[i]].freq++;
            hashTable[arr[i]].endIdx =i;
        }

        if(maxFreq<(hashTable[arr[i]].freq)){
            (*startIdx) = hashTable[arr[i]].startIdx;
            (*endIdx) = hashTable[arr[i]].endIdx;
           // printf("ins : %d %d\n",*startIdx,*endIdx);
            maxFreq = hashTable[arr[i]].freq;
        }
    }

}

int main(){
    
    int arr[] = {1, 2, 2, 3, 1};
    int size = sizeof(arr)/sizeof(int);

    int startIdx =0;
    int endIdx =0;
    
    for(int i=0;i<1000;i++){
        hashTable[i].freq =0;
        hashTable[i].startIdx =-1;
        hashTable[i].endIdx =-1;
    }

    smallestSubArrayWithAllOccurencesOfMostFreqEle(arr,&startIdx,&endIdx,size);
    printf("[%d %d] -> %d %d\n",startIdx,endIdx,arr[startIdx],arr[endIdx]);


}