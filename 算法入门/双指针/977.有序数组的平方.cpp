#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        vector<int> res(n, 0);
        while(--n >= 0){
            if(nums[left]*nums[left] > nums[right]*nums[right]){
                res[n] = nums[left]*nums[left];
                left++;
            }
            else{
                res[n] = nums[right]*nums[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

