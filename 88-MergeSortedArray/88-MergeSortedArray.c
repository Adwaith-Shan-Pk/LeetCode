// Last updated: 4/22/2026, 12:31:47 AM
1#include <stdlib.h>
2
3int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
4    int* result = (int*)malloc(numsSize * sizeof(int));
5    int left = 0, right = numsSize - 1;
6
7    for (int i = 0; i < numsSize; i++) {
8        if (nums[i] % 2 == 0)
9            result[left++] = nums[i];
10        else
11            result[right--] = nums[i];
12    }
13
14    *returnSize = numsSize;
15    return result;
16}