#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i == -1 || j == -1 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return ;
        
        grid[i][j] = '0';
        
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
        for(int t = 0; t < 4; t++){
            dfs(grid, i+x[t], j+y[t]);
        }
    }
};
// @lc code=end

