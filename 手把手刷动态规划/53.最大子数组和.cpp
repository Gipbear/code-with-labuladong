#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // dp[i]代表以i结尾最大的元素
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
        }
        int res = dp[0];
        for(int i = 1; i < n; i++){
            if(res < dp[i])
                res = dp[i];
        }
        return res;
    }
};
// @lc code=end

