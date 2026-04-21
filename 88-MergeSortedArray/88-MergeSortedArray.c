// Last updated: 4/22/2026, 12:32:28 AM
1#include <stdlib.h>
2
3int cmp(const void* a, const void* b) {
4    return (*(int*)a - *(int*)b);
5}
6
7int findContentChildren(int* g, int gSize, int* s, int sSize) {
8    qsort(g, gSize, sizeof(int), cmp);
9    qsort(s, sSize, sizeof(int), cmp);
10
11    int i = 0, j = 0;
12
13    while (i < gSize && j < sSize) {
14        if (s[j] >= g[i]) {
15            i++;  // child satisfied
16        }
17        j++;      // move to next cookie always
18    }
19
20    return i;
21}