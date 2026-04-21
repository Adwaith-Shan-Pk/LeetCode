// Last updated: 4/22/2026, 12:48:08 AM
#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int *ans = (int*)malloc((n + 1) * sizeof(int));

    ans[0] = 0;

    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}