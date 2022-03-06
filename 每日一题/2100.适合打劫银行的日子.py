#
# @lc app=leetcode.cn id=2100 lang=python3
#
# [2100] 适合打劫银行的日子
#

# @lc code=start
class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        down = [0]*n
        up = [0]*n
        c = 0
        for i in range(n-1, 0, -1):
            if security[i-1] <= security[i]:
                c += 1
                up[i-1] = c
            else:
                c = 0
        c = 0
        for i in range(1, n):
            if security[i-1] >= security[i]:
                c += 1
                down[i] = c
            else:
                c = 0
        res = []
        for i in range(n):
            if down[i] >= time and up[i] >= time:
                res.append(i)
        return res

# @lc code=end

