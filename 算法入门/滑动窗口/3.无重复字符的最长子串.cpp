#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int res = 0;
        int left = 0, right = 0;
        unordered_set<char> alpha;
        while(right < s.size()){
            char r = s[right];
            while(alpha.count(r)){
                alpha.erase(s[left++]);
            }
            alpha.insert(r);
            right++;
            res = max(res, right-left);
        }
        return res;
    }
};
// @lc code=end

