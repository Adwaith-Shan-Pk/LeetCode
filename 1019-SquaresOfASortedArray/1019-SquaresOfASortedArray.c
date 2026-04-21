// Last updated: 4/22/2026, 12:36:06 AM
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int left = 0, right = numsSize - 1;
    int pos = numsSize - 1;

    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];

        if (leftSq > rightSq) {
            result[pos--] = leftSq;
            left++;
        } else {
            result[pos--] = rightSq;
            right--;
        }
    }

    *returnSize = numsSize;
    return result;
}