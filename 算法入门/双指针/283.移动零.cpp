#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return ;
        }
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                nums[cur++] = nums[i];
        }
        for(int i = cur; i < n; i++){
            nums[i] = 0;
        }
    }
};
// @lc code=end

