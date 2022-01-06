#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
// class NumArray {
// private:
//     vector<int> nums;
// public:
//     NumArray(vector<int>& nums) {
//         this->nums = nums;
//     }
    
//     int sumRange(int left, int right) {
//         int sum = 0;
//         for(int i = left; i <= right; i++){
//             sum += this->nums[i];
//         }
//         return sum;
//     }
// };

// ! 由于在本次使用的过程中，sumRange会多次调用，所以在设计的时候可以使得构造函数复杂一些，而调用sumRange简单一些。所以使用前缀和来解决

class NumArray {
private:
    vector<int> presums;
public:
    NumArray(vector<int>& nums) {
        // 构造时为 n 的复杂度
        int n = nums.size();
        this->presums.resize(n+1);
        for(int i = 1; i < n+1; i++){
            this->presums[i] = this->presums[i-1] + nums[i-1];
        }
    }
    // 调用时仅需要直接索引相减即可
    int sumRange(int left, int right) {
        return this->presums[right+1] - this->presums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

