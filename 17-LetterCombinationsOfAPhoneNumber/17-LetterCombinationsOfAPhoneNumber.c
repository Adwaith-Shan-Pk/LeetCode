// Last updated: 4/22/2026, 12:55:31 AM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[10][5] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int idx, int len,
               char *path,
               char **res, int *returnSize) {

    if (idx == len) {
        path[len] = '\0';
        res[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
        strcpy(res[*returnSize], path);
        (*returnSize)++;
        return;
    }

    int d = digits[idx] - '0';
    char *letters = map[d];

    for (int i = 0; letters[i] != '\0'; i++) {
        path[idx] = letters[i];
        backtrack(digits, idx + 1, len, path, res, returnSize);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) return NULL;

    char **res = (char**)malloc(10000 * sizeof(char*));
    char *path = (char*)malloc((len + 1) * sizeof(char));

    backtrack(digits, 0, len, path, res, returnSize);

    free(path);
    return res;
}