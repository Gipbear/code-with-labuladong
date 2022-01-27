#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
// todo
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++){
            dp[i+1][0] = dp[i][0] + s1[i];
        }
        for(int j = 0; j < m; j++){
            dp[0][j+1] = dp[0][j] + s2[j];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(dp[i][j-1] < dp[i-1][j]){
                        dp[i][j] = dp[i][j-1] + s2[j-1];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + s1[i-1];
                    }
                }
            }
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};
// @lc code=end

