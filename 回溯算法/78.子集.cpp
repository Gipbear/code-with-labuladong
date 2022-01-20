#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subs;
        track_back(nums, 0, subs);
        return res;
    }

    void track_back(vector<int> &nums, int start, vector<int> &subs){
        // 这次实际上是需要将所有的路径过程全部加入
        // 所以这里不需要判断
        res.push_back(subs);
        for(int i = start; i < nums.size(); i++){
            subs.push_back(nums[i]);
            track_back(nums, i+1, subs);
            subs.pop_back();
        }
    }
};
// @lc code=end

