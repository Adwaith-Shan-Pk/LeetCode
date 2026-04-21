// Last updated: 4/22/2026, 12:55:20 AM
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *prefix;
    int n;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->n = numsSize;
    obj->prefix = (int*)malloc((numsSize + 1) * sizeof(int));

    obj->prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->prefix);
    free(obj);
}