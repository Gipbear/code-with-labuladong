#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> memo(row, vector<int>(col, 0));
        // 从右下角开始
        memo[row-1][col-1] = (1-dungeon[row-1][col-1] <= 0) ? 1 : (1-dungeon[row-1][col-1]);
        // 初始化最后一列
        for (int i = row-2; i >= 0; i--)
            memo[i][col-1] = (memo[i + 1][col-1] - dungeon[i][col-1] <= 0) ? 1 : (memo[i + 1][col-1] - dungeon[i][col-1]);
        // 初始化最后一行
        for (int i = col-2; i >= 0; i--)
            memo[row-1][i] = (memo[row-1][i + 1] - dungeon[row-1][i] <= 0) ? 1 : (memo[row-1][i + 1] - dungeon[row-1][i]);
        // dp
        for (int i = row-2; i >= 0; i--) {
            for (int j = col-2; j >= 0; j--) {
                memo[i][j] = (min(memo[i+1][j], memo[i][j+1]) - dungeon[i][j]) <= 0 ? 1 : min(memo[i+1][j], memo[i][j+1]) - dungeon[i][j];
            }
        }
        return memo[0][0];
    }
};
// @lc code=end
