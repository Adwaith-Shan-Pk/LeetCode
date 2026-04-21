// Last updated: 4/22/2026, 12:40:59 AM
1#include <stdio.h>
2
3int fib(int n) {
4    if (n <= 1) return n;
5
6    int a = 0, b = 1, c;
7
8    for (int i = 2; i <= n; i++) {
9        c = a + b;
10        a = b;
11        b = c;
12    }
13
14    return b;
15}