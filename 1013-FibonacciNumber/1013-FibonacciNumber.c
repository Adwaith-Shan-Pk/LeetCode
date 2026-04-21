// Last updated: 4/22/2026, 12:42:29 AM
#include <stdio.h>

int fib(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}