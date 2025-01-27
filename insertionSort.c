#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
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