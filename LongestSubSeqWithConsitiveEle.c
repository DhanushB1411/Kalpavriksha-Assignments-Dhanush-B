#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int longestConsecutive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    if (numsSize == 0) return 0;
    int count = 1;
    int maxConsAns = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] + 1 == nums[i + 1]) {
            count++;
        } else if (nums[i] == nums[i + 1]) {
            // Do nothing
        } else {
            count = 1;
        }
        if (maxConsAns <= count) {
            maxConsAns = count;
        }
    }
    return maxConsAns;
}


int longestConsectiveOptimal(int *nums,int numSize){
        
}
int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = longestConsecutive(nums, numsSize);
    printf("Length of the longest consecutive elements sequence: %d\n", result);
    return 0;
}