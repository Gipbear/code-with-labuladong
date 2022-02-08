#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
typedef pair<int, int> PII;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0, good;
        int m = grid.size(), n = grid[0].size();
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        queue<PII> q;
        bool flag = false; // 首先检查是否有新鲜橘子, 没有直接返回0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    good++;
                    flag == true;
                }
                else if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                }
            }
        }
        if(flag == false)
            return 0;
        
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int t_x = tmp.first + x[i];
                int t_y = tmp.second + y[i];
                if(t_x == -1 || t_y == -1 || t_x == m || t_y == n || grid[t_x][t_y] != 1)
                    continue;
                good--;
                grid[tmp.first][tmp.second] = 0;
                q.push(make_pair(t_x, t_y));
            }
            res++;
        }
        if(good)
            return -1;
        return res;
    }
};
// @lc code=end

