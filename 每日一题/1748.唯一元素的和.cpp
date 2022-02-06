#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> uni;
        for(int i = 0; i < nums.size();i++){
            uni[nums[i]]++;
        }
        int res=0;
        for(int i = 0; i < nums.size();i++){
            if(uni[nums[i]] == 1){
                res += nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

