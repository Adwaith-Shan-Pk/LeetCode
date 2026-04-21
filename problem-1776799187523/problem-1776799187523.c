// Last updated: 4/22/2026, 12:49:47 AM
1#include <stdio.h>
2#include <stdlib.h>
3
4void backtrack(int* nums, int numsSize, int start,
5               int* path, int pathSize,
6               int** res, int* returnSize,
7               int* colSizes) {
8    
9    res[*returnSize] = (int*)malloc(pathSize * sizeof(int));
10    for (int i = 0; i < pathSize; i++) {
11        res[*returnSize][i] = path[i];
12    }
13    colSizes[*returnSize] = pathSize;
14    (*returnSize)++;
15
16    for (int i = start; i < numsSize; i++) {
17        path[pathSize] = nums[i];
18        backtrack(nums, numsSize, i + 1, path, pathSize + 1, res, returnSize, colSizes);
19    }
20}
21
22int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
23    int maxSubsets = 1 << numsSize;
24
25    int** res = (int**)malloc(maxSubsets * sizeof(int*));
26    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));
27
28    int* path = (int*)malloc(numsSize * sizeof(int));
29    *returnSize = 0;
30
31    backtrack(nums, numsSize, 0, path, 0, res, returnSize, *returnColumnSizes);
32
33    free(path);
34    return res;
35}