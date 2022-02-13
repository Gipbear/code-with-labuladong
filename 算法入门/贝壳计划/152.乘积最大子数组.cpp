#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 由于乘到0会自动置0, 所以无需多考虑;
        // 累乘一定会使得数字绝对值递增!
        // 关键在于乘以负数会从最大变至最小, 以及从最小变成最大, 所以需要同时维护最大和最小值.
        int res = INT_MIN, iMax = 1, iMin = 1;
        for(int n : nums){
            if(n < 0){
                swap(iMax, iMin);
            }
            iMax = max(iMax * n, n);
            iMin = min(iMin * n, n);
            res = max(iMax, res);
        }
        return res;
    }
};
// @lc code=end

