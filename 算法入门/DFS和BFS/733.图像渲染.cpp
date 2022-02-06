#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, newColor, oldColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){
        if(sr == -1 || sc == -1 || sr == image.size() || sc == image[0].size() || image[sr][sc] != oldColor || image[sr][sc] == newColor)
            return ;
        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, newColor, oldColor);
        dfs(image, sr+1, sc, newColor, oldColor);
        dfs(image, sr, sc-1, newColor, oldColor);
        dfs(image, sr, sc+1, newColor, oldColor);
    }
};
// @lc code=end

