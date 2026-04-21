// Last updated: 4/22/2026, 12:21:12 AM
1int maxSubArray(int* nums, int numsSize) {
2    int maxSum = nums[0];
3    int currentSum = nums[0];
4
5    for (int i = 1; i < numsSize; i++) {
6        if (currentSum < 0)
7            currentSum = nums[i];
8        else
9            currentSum += nums[i];
10
11        if (currentSum > maxSum)
12            maxSum = currentSum;
13    }
14
15    return maxSum;
16}