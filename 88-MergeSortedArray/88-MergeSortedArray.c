// Last updated: 4/22/2026, 12:34:53 AM
1#include <stdbool.h>
2
3bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
4    for (int i = 0; i < flowerbedSize; i++) {
5        if (n == 0) return true;
6
7        if (flowerbed[i] == 0) {
8            int left = (i == 0) ? 0 : flowerbed[i - 1];
9            int right = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];
10
11            if (left == 0 && right == 0) {
12                flowerbed[i] = 1;
13                n--;
14            }
15        }
16    }
17
18    return n == 0;
19}