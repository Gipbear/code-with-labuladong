#
# @lc app=leetcode.cn id=2028 lang=python3
#
# [2028] 找出缺失的观测数据
#

# @lc code=start
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        rst = mean * (m+n) - sum(rolls)
        if rst / n > 6 or rst < n:
            return []
        else:
            res = [rst//n]*n
            for i in range(rst%n):
                res[i]+=1
        return res

# @lc code=end

