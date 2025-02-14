#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int i = 0, j = 0;
    int k = numsSize - 1;

    while (j <= k) {
        if (nums[j] == 0) {
            swap(&nums[i], &nums[j]);
            i++;
            j++;
        } else if (nums[j] == 1) {
            j++;
        } else {
            swap(&nums[j], &nums[k]);
            k--;
        }

        for (int i = 0; i < numsSize; i++) {
            printf(" %d ", nums[i]);
        }
        printf("\n");
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf(" %d ", nums[i]);
    }
    printf("\n\n");

    sortColors(nums, numsSize);

    printf("\nSorted array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf(" %d ", nums[i]);
    }
    printf("\n");

    return 0;
}