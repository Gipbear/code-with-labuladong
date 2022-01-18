#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
public:
    // 将日期转化为分钟格式进行计算
    int getMinutes(string &s){
        return (int(s[0]-'0')*10 + int(s[1]-'0'))*60 + int(s[3]-'0')*10 + int(s[4]-'0');
    }

    int findMinDifference(vector<string>& timePoints) {
        // 大于1440个元素必定有重复
        if (timePoints.size() > 1440) {
            return 0;
        }
        // 按照时间进行排序
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        // 第一个作为比较
        int toMinutes = getMinutes(timePoints[0]);
        int preMinutes = toMinutes;
        // 按照次序一一比较
        for(int i = 1; i < timePoints.size(); i++){
            int curMinutes = getMinutes(timePoints[i]);
            ans = min(curMinutes-preMinutes, ans);
            preMinutes = curMinutes;
        }
        // 隔天的时间进行比较
        ans = min(ans, toMinutes+1440-preMinutes);
        return ans;
    }
};
// @lc code=end

