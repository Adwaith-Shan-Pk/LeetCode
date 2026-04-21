// Last updated: 4/22/2026, 12:44:12 AM
1#include <stdio.h>
2#include <stdlib.h>
3
4int* countBits(int n, int* returnSize) {
5    *returnSize = n + 1;
6    int *ans = (int*)malloc((n + 1) * sizeof(int));
7
8    ans[0] = 0;
9
10    for (int i = 1; i <= n; i++) {
11        ans[i] = ans[i >> 1] + (i & 1);
12    }
13
14    return ans;
15}