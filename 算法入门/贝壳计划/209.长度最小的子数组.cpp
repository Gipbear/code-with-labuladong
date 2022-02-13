#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] > target)
                return 1;
            return 0;
        }
        int left = 0, right = 0;
        int res = 0, len = INT_MAX;
        while(right < n){
            if(res < target){
                res += nums[right];
                right++;
            }
            while(res >= target){
                len = min(len, right-left);
                res -= nums[left];
                left++;
            }
        }
        if(len == INT_MAX)
            return 0;
        return len;
    }
};
// @lc code=end

