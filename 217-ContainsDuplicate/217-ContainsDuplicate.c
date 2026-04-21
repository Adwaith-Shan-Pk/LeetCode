// Last updated: 4/22/2026, 12:18:13 AM
1#include <stdbool.h>
2#include <stdlib.h>
3
4// Simple hash set using sorting approach (since C has no built-in set)
5
6int compare(const void* a, const void* b) {
7    return (*(int*)a - *(int*)b);
8}
9
10bool containsDuplicate(int* nums, int numsSize) {
11    // Sort the array
12    qsort(nums, numsSize, sizeof(int), compare);
13    
14    // Check adjacent elements
15    for (int i = 1; i < numsSize; i++) {
16        if (nums[i] == nums[i - 1]) {
17            return true;
18        }
19    }
20    
21    return false;
22}