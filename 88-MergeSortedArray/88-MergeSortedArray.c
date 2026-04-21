// Last updated: 4/22/2026, 12:41:57 AM
1#include <stdio.h>
2
3int minCostClimbingStairs(int* cost, int costSize) {
4    int a = cost[0], b = cost[1], c;
5
6    for (int i = 2; i < costSize; i++) {
7        c = cost[i] + (a < b ? a : b);
8        a = b;
9        b = c;
10    }
11
12    return (a < b ? a : b);
13}