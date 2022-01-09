#include<iostream>
#include<unordered_map>
#include<string>
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
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        while(right < s.size()){
            // 扩张
            char c = s[right++];
            window[c]++;
            // 有重复的字符
            while(window[c] > 1){
                // 收缩
                char d = s[left++];
                window[d]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end

