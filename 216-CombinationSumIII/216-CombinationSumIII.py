# Last updated: 5/4/2026, 11:42:11 PM
1class Solution:
2    def combinationSum3(self, k, n):
3        res = []
4
5        def backtrack(start, path, total):
6            if len(path) == k:
7                if total == n:
8                    res.append(path[:])
9                return
10
11            for i in range(start, 10):
12                if total + i > n:
13                    break
14                path.append(i)
15                backtrack(i + 1, path, total + i)
16                path.pop()
17
18        backtrack(1, [], 0)
19        return res