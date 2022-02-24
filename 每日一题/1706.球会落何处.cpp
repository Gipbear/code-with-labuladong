#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int row = 0, col = i;
            while(row < m){
                if(grid[row][col] == 1){
                    if(col+1 >= n || grid[row][col+1] == -1){
                        res[i] = -1;
                        break;
                    }
                    if(grid[row][col+1] == 1){
                        col++;
                    }
                }
                else if(grid[row][col] == -1){
                    if(col-1 < 0 || grid[row][col-1] == 1){
                        res[i] = -1;
                        break;
                    }
                    if(grid[row][col-1] == -1){
                        col--;
                    }
                }
                row++;
                res[i] = col;
            }
        }
        return res;
    }
};
// @lc code=end

