// Last updated: 4/22/2026, 12:28:14 AM
1#include <stdlib.h>
2
3int* sortedSquares(int* nums, int numsSize, int* returnSize) {
4    int* result = (int*)malloc(numsSize * sizeof(int));
5    int left = 0, right = numsSize - 1;
6    int pos = numsSize - 1;
7
8    while (left <= right) {
9        int leftSq = nums[left] * nums[left];
10        int rightSq = nums[right] * nums[right];
11
12        if (leftSq > rightSq) {
13            result[pos--] = leftSq;
14            left++;
15        } else {
16            result[pos--] = rightSq;
17            right--;
18        }
19    }
20
21    *returnSize = numsSize;
22    return result;
23}