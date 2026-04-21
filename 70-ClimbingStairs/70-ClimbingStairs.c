// Last updated: 4/22/2026, 12:42:41 AM
#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) return n;

    int a = 1, b = 2, c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}