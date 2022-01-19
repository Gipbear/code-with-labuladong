#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        // 初始化为n个点
        vector<string> pos(n, string(n, '.'));
        track_back(pos, 0);
        return res;
    }

    void track_back(vector<string> &pos, int row){
        // 路径到底
        if(pos.size() == row){
            // 加入结果
            res.push_back(pos);
            return ;
        }
        int n = pos[row].size();
        for(int col = 0; col < n; col++){
            // 判断是否有效（路径合法）
            // 无效则继续
            if(!isValid(pos, row, col)){
                continue;
            }
            // 有效则新增
            pos[row][col] = 'Q';
            // 递归下一层
            track_back(pos, row+1);
            // 删除来回溯
            pos[row][col] = '.';
        }
    }

    bool isValid(vector<string> &pos, int row, int col){
        int n = pos.size();
        // 检查列冲突
        for(int i = 0; i < n; i++){
            if(pos[i][col] == 'Q')
                return false;
        }
        // 检查左上角
        for(int i = row-1, j = col-1; i>=0 &&j>=0; i--, j--){
            if(pos[i][j] == 'Q')
                return false;
        }
        // 检查右上角
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++){
            if(pos[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
// @lc code=end

