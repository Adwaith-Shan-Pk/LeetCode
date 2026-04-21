// Last updated: 4/22/2026, 12:20:35 AM
1int missingNumber(int* nums, int numsSize) {
2    int xor = numsSize;  // include n
3
4    for (int i = 0; i < numsSize; i++) {
5        xor ^= i ^ nums[i];
6    }
7
8    return xor;
9}