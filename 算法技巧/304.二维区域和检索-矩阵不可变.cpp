#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> prematrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        this->prematrix.resize(row+1, vector<int>(col+1));
        for(int i = 1; i < row+1; i++){
            for(int j = 1; j < col+1; j++){
                this->prematrix[i][j] = matrix[i-1][j-1] + this->prematrix[i-1][j] + this->prematrix[i][j-1] - this->prematrix[i-1][j-1];
                // cout<<this->prematrix[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;col2++;
        return this->prematrix[row2][col2] + this->prematrix[row1][col1] - this->prematrix[row1][col2] - this->prematrix[row2][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

