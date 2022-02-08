#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // 表示灯泡的位置
        set<vector<int>> open;
        /* 表示行、列、对角和斜对角是否被照亮
            row     col      diag   antidiag
            ----  | | | |  ↖↖↖↖  ↗↗↗↗
            ----  | | | |  ↖↖↖↖  ↗↗↗↗
            ----  | | | |  ↖↖↖↖  ↗↗↗↗
            ----  | | | |  ↖↖↖↖  ↗↗↗↗
            4条     4条       7条      7条(0到3+3)
                        (0-3+4-1到3-0+4-1)
        */
        unordered_map<int, int> row, col, diag, antidiag;
        for(auto l: lamps){
            // 标记新灯泡的影响
            if(! open.count(l)){
                open.insert(l);
                row[l[0]] += 1;
                col[l[1]] += 1;
                diag[l[1]-l[0]+n-1] += 1;
                antidiag[l[0]+l[1]] += 1;
            }
        }
        vector<int> res;
        vector<int> x = {0, 1,1,0,-1,-1,-1,0,1};
        vector<int> y = {0, 0,1,1,1,0,-1,-1,-1};
        for(auto q: queries){
            // 判断各个方向是否被照亮
            if(row[q[0]] or col[q[1]] or diag[q[1]-q[0]+n-1] or antidiag[q[0]+q[1]]){
                res.push_back(1);
            }
            else{
                res.push_back(0);
                // 未照亮则后续关闭无需进行
                continue;
            }
            // 否则关闭附近的电灯泡
            for(int k = 0; k < 9; k++){
                // 获得四周和本身-9个位置的坐标
                // 可以不考虑越界
                int i = q[0]+x[k], j = q[1]+y[k];
                if(open.count({i,j})){
                    open.erase({i,j});
                    row[i] -= 1;
                    col[j] -= 1;
                    diag[j-i+n-1] -= 1;
                    antidiag[i+j] -= 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

