#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> combs;
        track_back(combs, n, 1, k);
        return res;
    }

    void track_back(vector<int> &combs, int n, int start, int k){
        // 路径长度达到k
        if(combs.size() == k){
            res.push_back(combs);
            return ;
        }
        // 将序号后还为加入的数进行回溯
        for(int i = start; i <= n; i++){
            combs.push_back(i);
            track_back(combs, n, i+1, k);
            combs.pop_back();
        }
    }
};
// @lc code=end

