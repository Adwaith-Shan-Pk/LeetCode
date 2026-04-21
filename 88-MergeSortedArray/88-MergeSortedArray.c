// Last updated: 4/22/2026, 12:39:50 AM
1#include <stdio.h>
2#include <stdlib.h>
3
4int cmp(const void *a, const void *b) {
5    return (*(int*)a - *(int*)b);
6}
7
8int largestPerimeter(int* nums, int numsSize) {
9    qsort(nums, numsSize, sizeof(int), cmp);
10
11    for (int i = numsSize - 3; i >= 0; i--) {
12        long long a = nums[i];
13        long long b = nums[i + 1];
14        long long c = nums[i + 2];
15
16        if (a + b > c) {
17            return (int)(a + b + c);
18        }
19    }
20
21    return 0;
22}