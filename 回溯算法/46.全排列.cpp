#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        track_back(nums, path);
        return res;
    }

    void track_back(vector<int>& nums,vector<int>& path){
        if(path.size() == nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i=0; i < nums.size(); i++){
            // 如果路径中已经存在则跳过
            if(find(path.begin(), path.end(), nums[i]) != path.end()){
                continue;
            }
            // 不存在则加入路径
            path.push_back(nums[i]);
            track_back(nums, path);
            // 删除，进行回溯（重新再来）
            path.pop_back();
        }
    }
};
// @lc code=end

