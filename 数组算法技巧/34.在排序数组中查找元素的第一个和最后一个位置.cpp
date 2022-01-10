#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size()-1;
    //     int mid = left + (right-left)/2;
    //     bool flag = false;
    //     while(left <= right){
    //         if(nums[mid] == target){
    //             flag = true;
    //             break;
    //         }
    //         else if(nums[mid] > target){
    //             right = mid - 1;
    //         }
    //         else if(nums[mid] < target){
    //             left = mid + 1;
    //         }
    //         mid = left + (right-left)/2;
    //     }
    //     if(flag){
    //         left = mid;
    //         right = mid;
    //         while(--left >= 0 && nums[left] == target);
    //         while(++right < nums.size() && nums[right] == target);
    //         return {++left, --right};
    //     }
    //     return {-1,-1};
    // }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftRange(nums, target);
        if(left == -1){
            return {-1, -1};
        }
        int right = rightRange(nums, target);
        return {left, right};
    }

    int leftRange(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        int mid = left + (right-left)/2;
        while(left <= right){
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
            mid = left + (right-left)/2;
        }
        if(left >= nums.size() || nums[left] != target){
            return -1;
        }
        return left;
    }
    
    int rightRange(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        int mid = left + (right-left)/2;
        while(left <= right){
            if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
            mid = left + (right-left)/2;
        }
        if(right < 0 || nums[right] != target){
            return -1;
        }
        return right;
    }
};
// @lc code=end

