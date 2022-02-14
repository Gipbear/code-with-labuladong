#include<bits/stdc++.h>
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
        if(nums.size() == 1)
            return nums[0];
        int len = nums.size();
        int pre = nums[0];
        int res = nums[0];
        for(int i = 1; i < len; i++){
            pre = max(pre+nums[i], nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};
// @lc code=end

