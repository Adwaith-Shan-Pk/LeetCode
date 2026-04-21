// Last updated: 4/22/2026, 12:52:15 AM
1#include <stdio.h>
2#include <stdlib.h>
3
4void backtrack(int* candidates, int n, int target, int start,
5               int* path, int pathSize,
6               int** res, int* returnSize, int** colSizes) {
7    
8    if (target == 0) {
9        res[*returnSize] = (int*)malloc(pathSize * sizeof(int));
10        for (int i = 0; i < pathSize; i++) {
11            res[*returnSize][i] = path[i];
12        }
13        (*colSizes)[*returnSize] = pathSize;
14        (*returnSize)++;
15        return;
16    }
17
18    for (int i = start; i < n; i++) {
19        if (candidates[i] > target) continue;
20
21        path[pathSize] = candidates[i];
22        backtrack(candidates, n, target - candidates[i], i,
23                  path, pathSize + 1, res, returnSize, colSizes);
24    }
25}
26
27int** combinationSum(int* candidates, int candidatesSize, int target,
28                     int* returnSize, int** returnColumnSizes) {
29
30    int max = 150; // given constraint
31
32    int** res = (int**)malloc(max * sizeof(int*));
33    *returnColumnSizes = (int*)malloc(max * sizeof(int));
34
35    int* path = (int*)malloc(target * sizeof(int));
36
37    *returnSize = 0;
38
39    backtrack(candidates, candidatesSize, target, 0,
40              path, 0, res, returnSize, returnColumnSizes);
41
42    free(path);
43    return res;
44}