#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        vector<int> res;
        while(true){
            // 上
            for(int i = left; i <= right; i++)
                res.emplace_back(matrix[top][i]);
            if(++top > bottom) break;
            // 右
            for(int i = top; i <= bottom; i++)
                res.emplace_back(matrix[i][right]);
            if(--right < left) break;
            // 下
            for(int i = right; i >= left; i--)
                res.emplace_back(matrix[bottom][i]);
            if(--bottom < top) break;
            // 左
            for(int i = bottom; i >= top; i--)
                res.emplace_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};
// @lc code=end

