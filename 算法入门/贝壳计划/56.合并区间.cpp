#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int left = 0, right = 1;
        while(right < n){
            if(intervals[right][0] <= res[left][1]){
                res[left][1] = max(res[left][1], intervals[right][1]);
            }
            else{
                res.push_back(intervals[right]);
                left++;
            }
            right++;
        }
        return res;
    }
};
// @lc code=end

