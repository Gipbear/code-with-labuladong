#
# @lc app=leetcode.cn id=653 lang=python3
#
# [653] 两数之和 IV - 输入 BST
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        nums = []
        def traverse(root):
            if root == None:
                return
            traverse(root.left)
            nums.append(root.val)
            traverse(root.right)
            return
        
        traverse(root)
        left, right = 0, len(nums)-1
        while left < right:
            tmp = nums[left] + nums[right]
            if tmp == k:
                return True
            elif tmp < k:
                left += 1
            elif tmp > k:
                right -= 1
        return False
# @lc code=end

