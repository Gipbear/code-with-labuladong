#
# @lc app=leetcode.cn id=2044 lang=python3
#
# [2044] 统计按位或能得到最大值的子集数目
#

# @lc code=start
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        mask = 1 << n  # 枚举2*n种组合情况
        curMax, res = 0, 0
        for s in range(mask):
            cur = 0
            # 计算每种组合的值
            for i in range(n):
                if ((s>>i) & 1) == 1:
                    cur |= nums[i]
            # 记录最大值的个数
            if cur > curMax:
                curMax = cur
                res = 1
            elif cur == curMax:
                res += 1
        return res

# @lc code=end

