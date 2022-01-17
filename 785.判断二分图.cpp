#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
public:
    vector<bool> visited;  // 标记结点是否访问;
    vector<bool> colored;  // 标记结点是否着色;

    bool res = true; // 最后结果

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        colored = vector<bool>(n, false);
        // 图可能非连通, 需要遍历所有结点, 保证所有子图都是二分图
        for(int v = 0; v < n; v++){
            if(!visited[v])
                traverse(graph, v);
        }
        return res;
    }

    void traverse(vector<vector<int>>& graph, int v){
        // 若已经有结点判断为非连通, 则直接返回.
        if(!res)
            return;
        visited[v] = true;
        for(int w: graph[v]){
            // 若邻接点未访问过, 那么该点颜色标记与邻接点相反
            if(!visited[w]){
                colored[w] = !colored[v];
                traverse(graph, w);
            }
            // 若访问过, 则判断与邻接点颜色是否一致, 若一致则是非连通图
            else{
                if(colored[w] == colored[v])
                    res = false;
            }
        }
    }
};
// @lc code=end

