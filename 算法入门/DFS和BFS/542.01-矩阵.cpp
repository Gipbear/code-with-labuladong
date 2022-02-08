#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        queue<PII> q;
        // 0入队, 1置-1表示未访问, 与距离区分开;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    q.push(make_pair(i,j));
                else
                    mat[i][j] = -1;
            }
        }
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            // 结点向四周扩散, 计算距离
            for(int i = 0; i< 4; i++){
                int t_x = tmp.first+x[i];
                int t_y = tmp.second+y[i];
                // 越界或已经访问过
                if(t_x == -1 || t_y == -1 || t_x == m || t_y == n || mat[t_x][t_y] != -1)
                    continue;
                // 未访问则置为当前点加1
                mat[t_x][t_y] = mat[tmp.first][tmp.second] + 1;
                q.push(make_pair(t_x,t_y));
            }
        }
        return mat;
    }
};
// @lc code=end

