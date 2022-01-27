#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size();
        vector<vector<int>> dp(w1+1, vector<int>(w2+1, 0));
        for(int i = 1; i <= w1; i++){
            for(int j = 1; j <= w2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return w1+w2-2*dp[w1][w2];
    }
};
// @lc code=end

