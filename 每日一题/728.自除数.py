#
# @lc app=leetcode.cn id=728 lang=python3
#
# [728] 自除数
#

# @lc code=start
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []
        for num in range(left, right+1):
            p = num
            while p != 0:
                if p % 10 == 0 or num % (p%10) != 0:  # 存在0或无法整除，直接则跳出
                    break
                p = p // 10
            else:  # 未break，说明满足则加入
                res.append(num)
        return res
# @lc code=end

