// Last updated: 4/22/2026, 12:51:23 AM
1#include <stdio.h>
2#include <stdlib.h>
3#include <string.h>
4
5void backtrack(int n, int open, int close,
6               char *cur, int len,
7               char **res, int *returnSize) {
8
9    if (len == 2 * n) {
10        cur[len] = '\0';
11        res[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
12        strcpy(res[*returnSize], cur);
13        (*returnSize)++;
14        return;
15    }
16
17    if (open < n) {
18        cur[len] = '(';
19        backtrack(n, open + 1, close, cur, len + 1, res, returnSize);
20    }
21
22    if (close < open) {
23        cur[len] = ')';
24        backtrack(n, open, close + 1, cur, len + 1, res, returnSize);
25    }
26}
27
28char **generateParenthesis(int n, int *returnSize) {
29    int max = 1;
30    for (int i = 0; i < n; i++) max *= 2;
31
32    char **res = (char**)malloc(10000 * sizeof(char*));
33    char *cur = (char*)malloc((2 * n + 1) * sizeof(char));
34
35    *returnSize = 0;
36
37    backtrack(n, 0, 0, cur, 0, res, returnSize);
38
39    free(cur);
40    return res;
41}