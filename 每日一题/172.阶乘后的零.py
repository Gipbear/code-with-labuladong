#
# @lc app=leetcode.cn id=172 lang=python3
#
# [172] 阶乘后的零
#

# @lc code=start
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        fifth = 5
        while n >= fifth:
            res += n // fifth
            fifth *= 5
        return res

# @lc code=end

