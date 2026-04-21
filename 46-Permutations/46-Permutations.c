// Last updated: 4/22/2026, 12:50:36 AM
1#include <stdio.h>
2#include <stdlib.h>
3
4void swap(int *a, int *b) {
5    int t = *a;
6    *a = *b;
7    *b = t;
8}
9
10void backtrack(int *nums, int numsSize, int start,
11               int **res, int *returnSize, int **colSizes) {
12    
13    if (start == numsSize) {
14        res[*returnSize] = (int*)malloc(numsSize * sizeof(int));
15        for (int i = 0; i < numsSize; i++) {
16            res[*returnSize][i] = nums[i];
17        }
18        (*colSizes)[*returnSize] = numsSize;
19        (*returnSize)++;
20        return;
21    }
22
23    for (int i = start; i < numsSize; i++) {
24        swap(&nums[start], &nums[i]);
25        backtrack(nums, numsSize, start + 1, res, returnSize, colSizes);
26        swap(&nums[start], &nums[i]);
27    }
28}
29
30int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
31    int max = 1;
32    for (int i = 2; i <= numsSize; i++) max *= i;
33
34    int **res = (int**)malloc(max * sizeof(int*));
35    *returnColumnSizes = (int*)malloc(max * sizeof(int));
36    *returnSize = 0;
37
38    backtrack(nums, numsSize, 0, res, returnSize, returnColumnSizes);
39
40    return res;
41}