#include<stdlib.h>
#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
}

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int miniIdx =i;
        for(int j=i;j<n;j++)
        {
            if(arr[miniIdx]> arr[j])
            {
                miniIdx = j;
            }
        }

        swap(&arr[i],&arr[miniIdx]);
    }
}

void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int didSwap=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]> arr[j+1])
            {
                didSwap =1;
               swap(&arr[j],&arr[j+1]);
            }
        }
        if(didSwap == 0){
            printf(" break;\n");
            break;
        }

    }
}

void  insertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;

        while(j>0 && arr[j-1]>arr[j])
        {
            swap(&arr[j-1],&arr[j]);
            j--;
        }
    }

}
int main(){
    int arr[] = {2,6,1,6,34,8,2,3,8,2,9};

    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}