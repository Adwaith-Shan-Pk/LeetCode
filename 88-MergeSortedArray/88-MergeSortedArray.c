// Last updated: 4/22/2026, 12:49:00 AM
1#include <stdio.h>
2#include <stdlib.h>
3
4typedef struct {
5    int *prefix;
6    int n;
7} NumArray;
8
9NumArray* numArrayCreate(int* nums, int numsSize) {
10    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
11    obj->n = numsSize;
12    obj->prefix = (int*)malloc((numsSize + 1) * sizeof(int));
13
14    obj->prefix[0] = 0;
15    for (int i = 0; i < numsSize; i++) {
16        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
17    }
18
19    return obj;
20}
21
22int numArraySumRange(NumArray* obj, int left, int right) {
23    return obj->prefix[right + 1] - obj->prefix[left];
24}
25
26void numArrayFree(NumArray* obj) {
27    free(obj->prefix);
28    free(obj);
29}