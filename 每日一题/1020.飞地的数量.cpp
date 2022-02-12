#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        // 左右两侧向中间dfs
        for(int i = 0; i < row; i++){
            dfs(grid, i, 0);
            dfs(grid, i, col-1);
        }
        // 上下向中间dfs
        for(int j = 0; j < col; j++){
            dfs(grid, 0, j);
            dfs(grid, row-1, j);
        }
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1)
                    res += 1;
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &grid, int i, int j){
        int row = grid.size(), col = grid[0].size();
        if(i == -1 || j == -1 || i == row || j == col || grid[i][j] == 0){
            return ;
        }

        grid[i][j] = 0;

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        for(int t = 0; t < 4; t++){
            dfs(grid, i+x[t], j+y[t]);
        }
    }
};
// @lc code=end

