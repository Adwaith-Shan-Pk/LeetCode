// Last updated: 4/22/2026, 12:42:32 AM
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = numsSize - 3; i >= 0; i--) {
        long long a = nums[i];
        long long b = nums[i + 1];
        long long c = nums[i + 2];

        if (a + b > c) {
            return (int)(a + b + c);
        }
    }

    return 0;
}