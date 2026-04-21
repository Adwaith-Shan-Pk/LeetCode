// Last updated: 4/22/2026, 12:36:05 AM
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return y[1] - x[1];  // sort by units per box descending
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int*), cmp);

    int total = 0;

    for (int i = 0; i < boxTypesSize && truckSize > 0; i++) {
        int boxes = boxTypes[i][0];
        int units = boxTypes[i][1];

        int take = (boxes < truckSize) ? boxes : truckSize;

        total += take * units;
        truckSize -= take;
    }

    return total;
}