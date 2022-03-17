#
# @lc app=leetcode.cn id=720 lang=python3
#
# [720] 词典中最长的单词
#

# @lc code=start
class Solution:
    def longestWord(self, words: List[str]) -> str:
        words.sort()
        res = ""
        s = set()
        for w in words:
            if len(w) == 1 or w[:-1] in s:
                res = w if len(w) > len(res) else res
                s.add(w)
        return res
# @lc code=end

