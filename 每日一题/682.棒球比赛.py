#
# @lc app=leetcode.cn id=682 lang=python3
#
# [682] 棒球比赛
#

# @lc code=start
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack = []
        for i in ops:
            if i.lstrip('-').isdigit():
                stack.append(int(i))
            elif i == 'C':
                stack.pop()
            elif i == 'D':
                stack.append(stack[-1]*2)
            elif i == '+':
                stack.append(stack[-1] + stack[-2])
        return sum(stack)
# @lc code=end

