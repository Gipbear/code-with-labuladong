#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int left = 0, right = n-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if((mid & 1) == 0){
                if(mid + 1 < n && nums[mid] == nums[mid+1])
                    left = mid + 1;
                else
                    right = mid;
            }
            else{
                if(mid - 1 >= 0 && nums[mid] == nums[mid-1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[right];
    }
};
// @lc code=end

