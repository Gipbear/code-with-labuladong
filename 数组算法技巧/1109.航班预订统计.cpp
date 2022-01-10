#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 数组多一位，少一个判断好很多
        vector<int> res(n+1, 0);
        int booklen = bookings.size();
        for(int i = 0; i < booklen; i++){
            res[bookings[i][0]-1] += bookings[i][2];
            res[bookings[i][1]] -= bookings[i][2];
        }
        for(int i = 0; i < n; i++){
            res[i+1] += res[i];
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

