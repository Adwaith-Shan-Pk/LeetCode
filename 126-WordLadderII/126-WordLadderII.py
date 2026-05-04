# Last updated: 5/4/2026, 11:56:23 PM
1class Solution:
2    def buildTree(self, inorder, postorder):
3        index_map = {val: i for i, val in enumerate(inorder)}
4        self.post_idx = len(postorder) - 1
5
6        def dfs(left, right):
7            if left > right:
8                return None
9
10            
11            root_val = postorder[self.post_idx]
12            self.post_idx -= 1
13
14            root = TreeNode(root_val)
15
16            mid = index_map[root_val]
17
18            
19            root.right = dfs(mid + 1, right)
20            root.left = dfs(left, mid - 1)
21
22            return root
23
24        return dfs(0, len(inorder) - 1)