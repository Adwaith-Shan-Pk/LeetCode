// Last updated: 4/22/2026, 12:40:23 AM
1#include <stdio.h>
2
3int climbStairs(int n) {
4    if (n <= 2) return n;
5
6    int a = 1, b = 2, c;
7
8    for (int i = 3; i <= n; i++) {
9        c = a + b;
10        a = b;
11        b = c;
12    }
13
14    return b;
15}