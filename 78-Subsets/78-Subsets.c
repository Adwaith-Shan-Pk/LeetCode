// Last updated: 4/22/2026, 12:55:26 AM
#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start,
               int* path, int pathSize,
               int** res, int* returnSize,
               int* colSizes) {
    
    res[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) {
        res[*returnSize][i] = path[i];
    }
    colSizes[*returnSize] = pathSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, res, returnSize, colSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSubsets = 1 << numsSize;

    int** res = (int**)malloc(maxSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSubsets * sizeof(int));

    int* path = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, path, 0, res, returnSize, *returnColumnSizes);

    free(path);
    return res;
}