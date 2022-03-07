#
# @lc app=leetcode.cn id=504 lang=python3
#
# [504] 七进制数
#

# @lc code=start
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        flag = False
        if num < 0:
            flag = True
            num = -num
        res = ""
        while num != 0:
            res = str(num % 7) + res
            num //= 7
        if flag:
            res = "-" + res
        return res
# @lc code=end

