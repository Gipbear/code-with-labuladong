#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;
    int lengthOfLIS(vector<int>& nums) {
        // 这个备忘录的定义要定义恰当!
        // memo[n]用来记录到以nums[n]为尾的最大子序列
        memo = vector<int>(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                // 寻找在i之前比nums[i]小的memo备忘录来更新
                if(nums[i] > nums[j]){
                    memo[i] = max(memo[i], memo[j]+1);
                }
            }
        }
        int maxLen = memo[0];
        // 所有子序列中寻找最大的
        for(int m : memo){
            if(maxLen < m){
                maxLen = m;
            }
        }
        return maxLen;
    }
};
// @lc code=end

