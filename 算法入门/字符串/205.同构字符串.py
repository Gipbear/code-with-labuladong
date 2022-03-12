#
# @lc app=leetcode.cn id=205 lang=python3
#
# [205] 同构字符串
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        lookup = {}
        n = len(s)
        for i in range(n):
            if s[i] not in lookup.keys():
                if t[i] in lookup.values():
                    return False
                else:
                    lookup.setdefault(s[i], t[i])
            elif lookup[s[i]] != t[i]:
                return False
        return True
# @lc code=end

