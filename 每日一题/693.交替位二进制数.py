#
# @lc app=leetcode.cn id=693 lang=python3
#
# [693] 交替位二进制数
#

# @lc code=start
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        com = n & 1
        while n != 0:
            if n & 1 == com:
                com = 1 - com
            else:
                return False
            n = n >> 1
        return True

# @lc code=end

