// Last updated: 4/22/2026, 12:54:37 AM
1#include <stdio.h>
2#include <stdbool.h>
3
4bool isPowerOfTwo(int n) {
5    if (n <= 0) return false;
6    return (n & (n - 1)) == 0;
7}