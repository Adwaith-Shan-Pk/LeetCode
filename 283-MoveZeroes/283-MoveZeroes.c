// Last updated: 4/22/2026, 12:19:51 AM
1void moveZeroes(int* nums, int numsSize) {
2    int j = 0;  // position for next non-zero
3    
4    // Move all non-zero elements forward
5    for (int i = 0; i < numsSize; i++) {
6        if (nums[i] != 0) {
7            nums[j] = nums[i];
8            j++;
9        }
10    }
11    
12    // Fill remaining positions with zeros
13    while (j < numsSize) {
14        nums[j] = 0;
15        j++;
16    }
17}