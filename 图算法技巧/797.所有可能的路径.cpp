#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> opath;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traverse(graph, 0);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int s){
        opath.push_back(s);
        int n = graph.size();
        // 当遍历到最后一个结点
        if(s == n-1){
            res.push_back(opath);
            opath.pop_back();
            return ;
        }
        // 递归遍历每一个相邻结点
        for(int v : graph[s]){
            traverse(graph, v);
        }
        // 移除结点s
        opath.pop_back();
    }
};
// @lc code=end

