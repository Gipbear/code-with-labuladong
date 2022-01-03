#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:


    int numTrees(int n) {
        vector<vector<int>> memo(n+1,vector<int>(n+1, 0));
        return treeKinds(memo, 1, n);
    }

    int treeKinds(vector<vector<int>> &memo,int left, int right){
        if(left > right){
            return 1;
        }
        if(memo[left][right] != 0){
            return memo[left][right];
        }
        int res = 0;
        for (int i = left; i <= right; i++){
            int l = treeKinds(memo, left, i-1);
            int r = treeKinds(memo, i+1, right);
            res = res + l*r;
        }
        memo[left][right] = res;
        return res;
    }
};
// @lc code=end

