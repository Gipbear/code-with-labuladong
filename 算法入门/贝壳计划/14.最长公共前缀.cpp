#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) 
            return "";
        string ans = strs[0];
        int num=ans.length();
        for(int i =1;i<strs.size();i++) {
            int j=0;
            // 前缀是更小的长度
            if(num>strs[i].length())
                num=strs[i].length();
            for(; j < ans.length() && j < strs[i].length(); j++) {
                if(ans[j]!= strs[i][j]) {
                    if(j<num)
                        num=j;
                    break;
                }
            }
        }
        return ans.substr(0,num);
    }
};
// @lc code=end

