// Last updated: 4/22/2026, 12:36:09 AM
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int i = 0, j = 0;

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            i++;  // child satisfied
        }
        j++;      // move to next cookie always
    }

    return i;
}