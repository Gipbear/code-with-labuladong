#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size(), col = matrix[0].size();
        // 按行遍历
        for(int i = 0; i < row; i++) {
            int rowMin = matrix[i][0];  // 记录最小值
            int minCol = 0;  // 记录最小值所在的列
            // 找到该行最小值
            for(int j = 1; j < col; j++){
                if(matrix[i][j] < rowMin){
                    rowMin = matrix[i][j];
                    minCol = j;
                }
            }
            // 判断是否是该列最大值
            bool satisfied = true;
            for(int t = 0; t < row; t++){
                if(rowMin < matrix[t][minCol]){
                    satisfied = false;
                    break;
                }
            }
            if(satisfied){
                res.push_back(rowMin);
            }
        }
        return res;
    }
};
// @lc code=end

