#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int n, m;
    vector<vector<int>> grid;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(i, j));
                }
            }
        }
        return res;
    }

    int dfs(int i, int j){
        if(i == -1 || j == -1 || i == n || j == m || grid[i][j] == 0)
            return 0;
        int cnt = 1;
        grid[i][j] = 0;
        cnt += dfs(i-1, j);
        cnt += dfs(i+1, j);
        cnt += dfs(i, j-1);
        cnt += dfs(i, j+1);
        return cnt;
    }
};
// @lc code=end

