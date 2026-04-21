// Last updated: 4/22/2026, 12:21:52 AM
1int search(int* nums, int numsSize, int target) {
2    int left = 0, right = numsSize - 1;
3
4    while (left <= right) {
5        int mid = left + (right - left) / 2;
6
7        if (nums[mid] == target)
8            return mid;
9        else if (nums[mid] < target)
10            left = mid + 1;
11        else
12            right = mid - 1;
13    }
14
15    return -1;
16}