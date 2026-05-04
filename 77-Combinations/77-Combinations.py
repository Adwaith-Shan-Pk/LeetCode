# Last updated: 5/4/2026, 11:48:42 PM
1class Solution:
2    def permuteUnique(self, nums):
3        nums.sort()
4        res = []
5        used = [False] * len(nums)
6        
7        def backtrack(path):
8            if len(path) == len(nums):
9                res.append(path[:])
10                return
11            
12            for i in range(len(nums)):
13                
14                if used[i]:
15                    continue
16                
17                
18                if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
19                    continue
20                
21                used[i] = True
22                path.append(nums[i])
23                
24                backtrack(path)
25                
26                path.pop()
27                used[i] = False
28        
29        backtrack([])
30        return res