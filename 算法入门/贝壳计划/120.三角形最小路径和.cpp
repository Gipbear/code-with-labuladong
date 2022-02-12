#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size(), width = triangle[height-1].size();
        if(height == 1)
            return triangle[0][0];
        vector<int> dp(width+1, 10000);
        dp[1] = triangle[0][0];
        for(int i = 1; i < height; i++){
            for(int j = triangle[i].size(); j >= 1; j--){
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j-1];
            }
        }
        int res = dp[1];
        for(int i = 2; i <= width; i++){
            res = min(dp[i], res);
        }
        return res;
    }
};
// @lc code=end

