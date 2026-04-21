// Last updated: 4/22/2026, 12:23:37 AM
1int firstBadVersion(int n) {
2    int left = 1, right = n;
3
4    while (left < right) {
5        int mid = left + (right - left) / 2;
6
7        if (isBadVersion(mid))
8            right = mid;      // first bad is at mid or before
9        else
10            left = mid + 1;   // first bad is after mid
11    }
12
13    return left;
14}
15