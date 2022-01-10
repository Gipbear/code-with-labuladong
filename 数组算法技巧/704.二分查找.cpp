#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; // 右侧需要减一
        // 计算 mid 时需要防止太大溢出
        int mid = left + (right-left)/2;
        while(left <= right){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid +1;
            }
            mid = left + (right-left)/2;
        }
        return -1;
    }
};
// @lc code=end

