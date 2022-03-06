#
# @lc app=leetcode.cn id=258 lang=python3
#
# [258] 各位相加
#

# @lc code=start
class Solution:
    def Sum(self, num):
        res = 0
        while num != 0:
            res += num % 10
            num = num // 10
        return res

    def addDigits(self, num: int) -> int:
        while num > 9:
            num = self.Sum(num)
        return num
# @lc code=end

