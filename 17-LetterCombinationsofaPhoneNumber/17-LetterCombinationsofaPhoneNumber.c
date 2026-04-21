// Last updated: 4/22/2026, 12:53:58 AM
1#include <stdio.h>
2#include <stdlib.h>
3#include <string.h>
4
5char map[10][5] = {
6    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
7};
8
9void backtrack(char *digits, int idx, int len,
10               char *path,
11               char **res, int *returnSize) {
12
13    if (idx == len) {
14        path[len] = '\0';
15        res[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
16        strcpy(res[*returnSize], path);
17        (*returnSize)++;
18        return;
19    }
20
21    int d = digits[idx] - '0';
22    char *letters = map[d];
23
24    for (int i = 0; letters[i] != '\0'; i++) {
25        path[idx] = letters[i];
26        backtrack(digits, idx + 1, len, path, res, returnSize);
27    }
28}
29
30char **letterCombinations(char *digits, int *returnSize) {
31    *returnSize = 0;
32    int len = strlen(digits);
33    if (len == 0) return NULL;
34
35    char **res = (char**)malloc(10000 * sizeof(char*));
36    char *path = (char*)malloc((len + 1) * sizeof(char));
37
38    backtrack(digits, 0, len, path, res, returnSize);
39
40    free(path);
41    return res;
42}