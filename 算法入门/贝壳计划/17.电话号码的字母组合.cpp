#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> d2s = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        for(char ch: d2s[digits[0]-'0']){
            string tmp;
            tmp.push_back(ch);
            track_back(digits, 1, tmp);
        }
        return res;
    }
    // pos表示第几层，cur是当前字符串
    void track_back(string digits, int pos, string cur){
        if(cur.size() == digits.size()){
            res.push_back(cur);
            return ;
        }
        for(char ch: d2s[digits[pos]-'0']){
            cur.push_back(ch);
            track_back(digits, pos+1, cur);
            cur.pop_back();
        }
    }
};
// @lc code=end

