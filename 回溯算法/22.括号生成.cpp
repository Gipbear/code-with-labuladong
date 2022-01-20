#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string path = "";
        int left = 0, right = 0;
        track_back(path, left, right, n);
        return res;
    }

    void track_back(string &path, int left, int right, int n){
        if(path.size() == 2*n){
            res.push_back(path);
            return ;
        }
        if(left < n){
            path.push_back('(');
            left++;
            track_back(path, left, right, n);
            path.pop_back();
            left--;
        }
        if(right < left){
            path.push_back(')');
            right++;
            track_back(path, left, right, n);
            path.pop_back();
            right--;
        }    }
};
// @lc code=end

