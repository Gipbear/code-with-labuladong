#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 100000;
        for(int left = 0; left+k-1 < nums.size(); left++)
            res = min(res, nums[left+k-1]-nums[left]);
        return res;
    }
};
// @lc code=end

