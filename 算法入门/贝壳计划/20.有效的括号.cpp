#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // 作为字符栈
        vector<char> s_stack;
        for(int i = 0; i < s.size(); i++){
            if(s_stack.empty()){
                s_stack.push_back(s[i]);
            }
            else if(s[i]-s_stack.back() == 1 || s[i]-s_stack.back() == 2){
                s_stack.pop_back();
            }
            else{
                s_stack.push_back(s[i]);
            }
        }
        if(s_stack.empty())
            return true;
        return false;
    }
};
// @lc code=end

