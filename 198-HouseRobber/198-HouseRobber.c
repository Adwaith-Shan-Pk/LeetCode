// Last updated: 4/22/2026, 12:48:12 AM
#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];

    int prev2 = 0;
    int prev1 = 0;
    int curr;

    for (int i = 0; i < numsSize; i++) {
        int take = prev2 + nums[i];
        int skip = prev1;

        curr = take > skip ? take : skip;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}