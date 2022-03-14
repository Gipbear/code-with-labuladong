#
# @lc app=leetcode.cn id=599 lang=python3
#
# [599] 两个列表的最小索引总和
#

# @lc code=start
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        lookup = {li:i for i, li in enumerate(list1)}
        res = []
        indSum = 2000
        for i, li in enumerate(list2):
            if li in lookup.keys():
                j = lookup[li]
                if i + j < indSum:
                    indSum = i + j
                    res = [li]
                elif i + j == indSum:
                    res.append(li)
        return res
# @lc code=end

