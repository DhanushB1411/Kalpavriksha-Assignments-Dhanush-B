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

int subarraysWithKDistinct(int* nums, int numsSize, int k) {
    Hash hash;
    initHash(&hash);

    int maxSubArrays = 0;

    for (int i = 0; i < numsSize; i++) {
        initHash(&hash);
        for (int j = i; j < numsSize; j++) {
            insertHash(nums[j], &hash);
            if (hash.size == k) {
                maxSubArrays++;
            } else if (hash.size > k) {
                continue;
            }
        }
    }
    return maxSubArrays;
}

int main() {
    int nums[] = {1, 2, 1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int result = subarraysWithKDistinct(nums, numsSize, k);
    printf("distinct elements: %d\n",result);
    return 0;
}