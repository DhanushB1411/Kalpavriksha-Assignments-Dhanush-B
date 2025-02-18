#include<stdio.h>
#include<stdlib.h>

#define MAX_NUM 20001

typedef struct {
    int hashArray[MAX_NUM];
    int size;
} Hash;

void insertHash(int num, Hash *hash) {
    if (hash->hashArray[num] > 0) {
        hash->hashArray[num]++;
        return;
    }
    hash->hashArray[num]++;
    hash->size++;
}

void deleteHash(int num, Hash *hash) {
    if (hash->hashArray[num] > 0) {
        hash->hashArray[num]--;
        if (hash->hashArray[num] == 0) {
            hash->size--;
        }
    }
}

void initHash(Hash *hash) {
    for (int i = 0; i < MAX_NUM; i++) {
        hash->hashArray[i] = 0;
    }
    hash->size = 0;
}

int solvesubarraysWithKDistinct(int* nums, int numsSize, int k) {
    Hash hash;
    initHash(&hash);

    int left = 0;
    int right = 0;
    int maxSubArrays = 0;

    while (right < numsSize) {
        insertHash(nums[right], &hash);

        while (hash.size > k) {
            deleteHash(nums[left], &hash);
            left++;
        }

        if (hash.size <= k) {
            maxSubArrays = maxSubArrays + (right - left + 1);
        }
        right++;
    }

    return maxSubArrays;
}

int subarraysWithKDistinct(int* nums, int numsSize, int k) {
    return (solvesubarraysWithKDistinct(nums, numsSize, k) - solvesubarraysWithKDistinct(nums, numsSize, k - 1));
}

int main() {
    int nums[] = {1, 2, 1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int result = subarraysWithKDistinct(nums, numsSize, k);
    printf("Number of subarrays with exactly %d distinct elements: %d\n", k, result);
    return 0;
}