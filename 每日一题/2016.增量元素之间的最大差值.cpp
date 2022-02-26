#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minNum = INT_MAX, maxDiff = 0;
        for(int n : nums){
            maxDiff = max(maxDiff, n-minNum);
            minNum = min(minNum, n);
        }
        return maxDiff > 0 ? maxDiff : -1;
    }
};
// @lc code=end

