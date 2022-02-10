#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        string cur;
        track_back(s, cur, 0);
        return res;
    }
    void track_back(string s, string cur, int pos){
        if(cur.size() == s.size()){
            res.push_back(cur);
            return ;
        }
        cur.push_back(s[pos]);
        track_back(s, cur, pos+1);
        cur.pop_back();
        if('A' <= s[pos] && s[pos] <= 'Z'){
            cur.push_back(s[pos]-'A'+'a');
            track_back(s, cur, pos+1);
        }
        else if('a' <= s[pos] && s[pos] <= 'z'){
            cur.push_back(s[pos]-'a'+'A');
            track_back(s, cur, pos+1);
        }
        cur.pop_back();
    }
};
// @lc code=end

