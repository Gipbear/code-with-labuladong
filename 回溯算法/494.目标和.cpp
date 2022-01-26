#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int result = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        track_back(nums, 0, target);
        return result;
    }

    // n是选择第几个数, rest是距离目标值还差多少
    void track_back(vector<int>& nums, int n, int rest){
        if(n == nums.size()){
            if(rest == 0){
                result++;
            }
            return ;
        }
        // 减法回溯——这里是rest, 所以减去加数
        rest += nums[n];
        track_back(nums, n+1, rest);
        rest -= nums[n];

        // 加法回溯
        rest -= nums[n];
        track_back(nums, n+1, rest);
        rest += nums[n];
    }
};
// @lc code=end

