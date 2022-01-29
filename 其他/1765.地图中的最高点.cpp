#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        // 标记水域数值为0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        // 方便遍历上下左右
        int dx[4] = {-1,0,1,0}, dy[4]={0,1,0,-1};
        // 按照队列处理，以水域为中心扩散，每次加一
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            // 上下左右
            for(int i = 0; i < 4; i++){
                int x = t.first + dx[i], y = t.second + dy[i];
                // 数组越界或未访问过， 则跳过
                if(x < 0 || x >= n || y < 0 || y >= m || res[x][y] != -1)
                    continue;
                res[x][y] = res[t.first][t.second] + 1;
                q.push({x,y});
            }
        }
        return res;
    }
};
// @lc code=end

