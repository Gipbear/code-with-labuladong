#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
 */

// @lc code=start
class Solution {
public:
    int x[8] = {1,2,2,1,-1,-2,-2,-1};
    int y[8] = {2,1,-1,-2,-2,-1,1,2};
    unordered_map<int, unordered_map<int, double>> memo;

    double knightProbability(int n, int k, int row, int column) {
        return dfs(n, row, column, k);
    }

    double dfs(int n, int i, int j, int k){
        if(k == 0){
            return 1;
        }
        if(memo[i*n+j].count(k))
            return memo[i*n+j][k];
        
        double p = 0;
        for(int t = 0; t < 8; t++){
            int row = i + x[t], col = j + y[t];
            if(row <= -1 || col <= -1 || row >= n || col >= n)
                continue;
            p += dfs(n, row, col, k-1) / 8;
        }
        memo[i*n+j][k] = p;
        return p;
    }
};
// @lc code=end

