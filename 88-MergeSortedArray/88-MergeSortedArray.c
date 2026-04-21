// Last updated: 4/22/2026, 12:35:28 AM
1#include <stdlib.h>
2
3int cmp(const void* a, const void* b) {
4    return (*(int*)a - *(int*)b);
5}
6
7// helper: number of starts <= x
8int countStarts(int* arr, int n, int x) {
9    int l = 0, r = n;
10    while (l < r) {
11        int m = l + (r - l) / 2;
12        if (arr[m] <= x) l = m + 1;
13        else r = m;
14    }
15    return l;
16}
17
18// helper: number of ends < x
19int countEnds(int* arr, int n, int x) {
20    int l = 0, r = n;
21    while (l < r) {
22        int m = l + (r - l) / 2;
23        if (arr[m] < x) l = m + 1;
24        else r = m;
25    }
26    return l;
27}
28
29int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize,
30                      int* people, int peopleSize, int* returnSize) {
31
32    int* starts = (int*)malloc(flowersSize * sizeof(int));
33    int* ends   = (int*)malloc(flowersSize * sizeof(int));
34
35    for (int i = 0; i < flowersSize; i++) {
36        starts[i] = flowers[i][0];
37        ends[i] = flowers[i][1];
38    }
39
40    qsort(starts, flowersSize, sizeof(int), cmp);
41    qsort(ends, flowersSize, sizeof(int), cmp);
42
43    int* ans = (int*)malloc(peopleSize * sizeof(int));
44
45    for (int i = 0; i < peopleSize; i++) {
46        int p = people[i];
47
48        int started = countStarts(starts, flowersSize, p);
49        int ended = countEnds(ends, flowersSize, p);
50
51        ans[i] = started - ended;
52    }
53
54    free(starts);
55    free(ends);
56
57    *returnSize = peopleSize;
58    return ans;
59}