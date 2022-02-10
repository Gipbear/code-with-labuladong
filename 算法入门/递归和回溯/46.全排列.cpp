#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        track_back(nums, cur, nums.size());
        return res;
    }

    void track_back(vector<int>& nums, vector<int> &cur, int n){
        if(cur.size() == n){
            res.push_back(cur);
            return ;
        }
        for(int i = 0; i < n; i++){
            if(find(cur.begin(), cur.end(), nums[i]) != cur.end())
                continue;
            cur.push_back(nums[i]);
            track_back(nums, cur, n);
            cur.pop_back();
        }
    }
};
// @lc code=end

