// Last updated: 4/22/2026, 12:36:03 AM
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// helper: number of starts <= x
int countStarts(int* arr, int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}

// helper: number of ends < x
int countEnds(int* arr, int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize,
                      int* people, int peopleSize, int* returnSize) {

    int* starts = (int*)malloc(flowersSize * sizeof(int));
    int* ends   = (int*)malloc(flowersSize * sizeof(int));

    for (int i = 0; i < flowersSize; i++) {
        starts[i] = flowers[i][0];
        ends[i] = flowers[i][1];
    }

    qsort(starts, flowersSize, sizeof(int), cmp);
    qsort(ends, flowersSize, sizeof(int), cmp);

    int* ans = (int*)malloc(peopleSize * sizeof(int));

    for (int i = 0; i < peopleSize; i++) {
        int p = people[i];

        int started = countStarts(starts, flowersSize, p);
        int ended = countEnds(ends, flowersSize, p);

        ans[i] = started - ended;
    }

    free(starts);
    free(ends);

    *returnSize = peopleSize;
    return ans;
}