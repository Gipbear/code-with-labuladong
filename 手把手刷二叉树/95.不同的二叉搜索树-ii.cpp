#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {nullptr};
        return build(1,n);
    }
    
    vector<TreeNode*> build(int low, int high){
        if(low > high){
            return {nullptr};
        }
        if (low == high) {
            return {new TreeNode(low)};
        }
        vector<TreeNode*> res;
        for(int i = low; i <= high; i++){
            vector<TreeNode*> leftTree = build(low, i-1);
            vector<TreeNode*> rightTree = build(i+1, high);
            for(TreeNode* left: leftTree){
                for(TreeNode* right: rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

