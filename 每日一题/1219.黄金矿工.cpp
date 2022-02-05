#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0)
                    dfs(grid, i, j, 0);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int gold){
        // base case
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return ;
        int g = grid[i][j];
        gold += g;
        grid[i][j] = 0; // 标记访问过
        // 比较当前最值
        res = max(res, gold);

        // 递归各个方向
        dfs(grid, i-1, j, gold); // 上
        dfs(grid, i+1, j, gold); // 下
        dfs(grid, i, j-1, gold); // 左
        dfs(grid, i, j+1, gold); // 右

        // 回溯
        gold -= g;
        grid[i][j] = g;
    }
};
// @lc code=end

