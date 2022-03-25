#
# @lc app=leetcode.cn id=2038 lang=python3
#
# [2038] 如果相邻两个颜色均相同则删除当前颜色
#

# @lc code=start
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        l1 = colors.split('A')
        l2 = colors.split('B')
        numA, numB = 0, 0
        for i in l1:
            if len(i) >= 3:
                numB += len(i) - 2
        for i in l2:
            if len(i) >= 3:
                numA += len(i) - 2
        return numA > numB
# @lc code=end

