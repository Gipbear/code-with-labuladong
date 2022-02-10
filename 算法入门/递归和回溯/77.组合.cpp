#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        track_back(cur, 1, n, k);
        return res;
    }
    void track_back(vector<int> &cur, int i, int n, int k){
        if(cur.size() == k){
            res.push_back(cur);
            return ;
        }
        for(int j = i; j <= n; j++){
            cur.push_back(j);
            track_back(cur, j+1, n, k);
            cur.pop_back();
        }
    }
};
// @lc code=end

