#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxsize = 0;
        for(int i = 0; i < trips.size(); i++){
            // 一次性上客数超过最大容量直接pass
            if(capacity < trips[i][0])
                return false;
            // 计算需要的最大容量
            if(maxsize < trips[i][2])
                maxsize = trips[i][2];
        }
        // 包含头尾，需要+2
        vector<int> res(maxsize+2, 0);
        // 计算差分
        for(int i = 0; i < trips.size(); i++){
            res[trips[i][1]] += trips[i][0];
            res[trips[i][2]] -= trips[i][0];
        }
        // 还原差分，判断是否超载
        for(int i = 0; i < maxsize+1; i++){
            res[i+1] += res[i];
            if(res[i+1] > capacity){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

