#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1725 lang=cpp
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0, cnt = 0;
        for(int i = 0; i < rectangles.size(); i++){
            int maxLen = min(rectangles[i][0], rectangles[i][1]);
            if(maxLen > res){
                res = maxLen;
                cnt = 1;
            }
            else if(maxLen == res){
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

