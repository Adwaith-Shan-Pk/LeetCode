// Last updated: 4/22/2026, 12:30:43 AM
1void merge(int* nums1, int nums1Size, int m,
2           int* nums2, int nums2Size, int n) {
3    
4    int i = m - 1;
5    int j = n - 1;
6    int k = m + n - 1;
7
8    while (i >= 0 && j >= 0) {
9        if (nums1[i] > nums2[j])
10            nums1[k--] = nums1[i--];
11        else
12            nums1[k--] = nums2[j--];
13    }
14
15    while (j >= 0) {
16        nums1[k--] = nums2[j--];
17    }
18}