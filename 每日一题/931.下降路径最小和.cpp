#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    matrix[i][j] = min(matrix[i-1][j], matrix[i-1][j+1]) + matrix[i][j];
                }
                else if(j == n-1){
                    matrix[i][j] = min(matrix[i-1][j], matrix[i-1][j-1]) + matrix[i][j];
                }
                else{
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1])) + matrix[i][j];
                }
            }
        }

        int res = matrix[n-1][0];
        for(int j = 1; j < n; j++){
            if(res > matrix[n-1][j]){
                res = matrix[n-1][j];
            }
        }
        return res;
    }
};
// @lc code=end

