#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
public:

    vector<bool> visited;
    vector<bool> colored;

    bool res = true;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph = buildGraph(n, dislikes);
        visited = vector<bool>(n+1, false);
        colored = vector<bool>(n+1, false);
        for(int v = 1; v <= n; v++){
            if(!visited[v])
                traverse(graph, v);
        }
        return res;
    }

    // 将dislikes化为图结构
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes){
        vector<vector<int>> graph(n+1, vector<int>());
        for(vector<int> d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        return graph;
    }

    void traverse(vector<vector<int>> &graph, int v){
        if(!res)
            return;
        visited[v] = true;
        for(int w: graph[v]){
            if(!visited[w]){
                colored[w] = !colored[v];
                traverse(graph, w);
            }
            else{
                if(colored[w] == colored[v])
                    res = false;
            }
        }
    }
};
// @lc code=end

