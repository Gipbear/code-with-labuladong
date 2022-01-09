#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // need是子串元素hash，window是滑动窗口
        unordered_map<char, int> need, window;
        // 初始化need子串
        for(char c : t)
            need[c]++;
        int left = 0, right = 0; // 区间左闭右开
        int valid = 0;  // 窗口内有效元素个数
        int start = 0, len = INT_MAX;  // 最终起点和长度
        while(right < s.size()){
            char c = s[right];  //右移字符进入子串hash
            right++;
            if(need.count(c)){  //若需要则修改hash
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            while(valid == need.size()){  //窗口内的元素已经满足需要
                if(right-left < len){  // 可以收缩窗口就更新结果
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

