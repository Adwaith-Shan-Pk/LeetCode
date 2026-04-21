// Last updated: 4/22/2026, 12:34:16 AM
1#include <stdlib.h>
2
3int cmp(const void* a, const void* b) {
4    int* x = *(int**)a;
5    int* y = *(int**)b;
6    return y[1] - x[1];  // sort by units per box descending
7}
8
9int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
10    qsort(boxTypes, boxTypesSize, sizeof(int*), cmp);
11
12    int total = 0;
13
14    for (int i = 0; i < boxTypesSize && truckSize > 0; i++) {
15        int boxes = boxTypes[i][0];
16        int units = boxTypes[i][1];
17
18        int take = (boxes < truckSize) ? boxes : truckSize;
19
20        total += take * units;
21        truckSize -= take;
22    }
23
24    return total;
25}