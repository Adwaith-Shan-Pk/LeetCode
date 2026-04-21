// Last updated: 4/22/2026, 12:42:34 AM
#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize) {
    int a = cost[0], b = cost[1], c;

    for (int i = 2; i < costSize; i++) {
        c = cost[i] + (a < b ? a : b);
        a = b;
        b = c;
    }

    return (a < b ? a : b);
}