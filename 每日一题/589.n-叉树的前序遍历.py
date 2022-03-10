#
# @lc app=leetcode.cn id=589 lang=python3
#
# [589] N 叉树的前序遍历
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []

        def dfs(root):
            if root is None:
                return
            res.append(root.val)
            for ch in root.children:
                dfs(ch)

        dfs(root)
        return res
# @lc code=end

