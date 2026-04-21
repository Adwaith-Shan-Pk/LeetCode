// Last updated: 4/22/2026, 12:36:01 AM
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int left = 0, right = numsSize - 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0)
            result[left++] = nums[i];
        else
            result[right--] = nums[i];
    }

    *returnSize = numsSize;
    return result;
}