#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    // 方法1
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;  // 取余
    //     vector<int> tmp(k);
    //     int j = 0;
    //     for(int i = n-k; i < n; i++){
    //         tmp[j++] = nums[i];
    //     }
    //     for(int i = n-k-1; i >= 0; i--){
    //         nums[i+k] = nums[i];
    //     }
    //     for(int i = 0; i < k; i++){
    //         nums[i] = tmp[i];
    //     }
    // }

    // 方法2
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
    void reverse(vector<int>&nums, int left, int right){
        while(left < right){
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }

    // 方法3
    // void rotate(vector<int>& nums, int k){
    //     int n = nums.size();
    //     vector<int> tmp(n);
    //     for(int i = 0; i < n; i++){
    //         tmp[(i+k)%n] = nums[i];
    //     }
    //     nums = tmp;
    // }
};
// @lc code=end

