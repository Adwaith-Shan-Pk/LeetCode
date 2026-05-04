# Last updated: 5/4/2026, 11:49:09 PM
1class Solution:
2    def removeInvalidParentheses(self, s):
3        from collections import deque
4
5        def is_valid(st):
6            bal = 0
7            for ch in st:
8                if ch == '(':
9                    bal += 1
10                elif ch == ')':
11                    bal -= 1
12                    if bal < 0:
13                        return False
14            return bal == 0
15
16        res = []
17        visited = set([s])
18        q = deque([s])
19        found = False
20
21        while q:
22            cur = q.popleft()
23
24            if is_valid(cur):
25                res.append(cur)
26                found = True
27
28            if found:
29                continue
30
31            for i in range(len(cur)):
32                if cur[i] not in '()':
33                    continue
34                nxt = cur[:i] + cur[i+1:]
35                if nxt not in visited:
36                    visited.add(nxt)
37                    q.append(nxt)
38
39        return res