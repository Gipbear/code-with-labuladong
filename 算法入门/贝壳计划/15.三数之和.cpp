#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        // 排序便于去重
        sort(nums.begin(), nums.end());
        if(nums[0] > 0){
            return {};
        }
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            int l = i+1, r = nums.size()-1;
            int first = -nums[i];
            while(l < r){
                int left = nums[l], right = nums[r];
                int sum = left + right;
                if(sum < first){
                    while(l < r && nums[l] == left) l++;
                }
                else if(sum > first){
                    while(l < r && nums[r] == right) r--;
                }
                else {
                    res.push_back({-first, left, right});
                    while(l < r && nums[l] == left) l++;
                    while(l < r && nums[r] == right) r--;
                }
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }

};
// @lc code=end

