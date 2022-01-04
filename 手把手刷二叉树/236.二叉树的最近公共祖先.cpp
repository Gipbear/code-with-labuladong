#include<iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 结点为空，自然是没有
        if(root == nullptr){
            return nullptr;
        }
        // 结点就是p或q，那么就是该结点
        if(root == p || root == q){
            return root;
        }
        // 否则就是左或右结点
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 左右结点均不为空，那么就是该结点
        if(left != nullptr && right != nullptr){
            return root;
        }
        // 左右结点均为空，那么就不存在
        if(left == nullptr && right == nullptr){
            return nullptr;
        }
        // 有一个结点不为空，那么就是不为空的结点
        return left == nullptr ? right : left;
    }
};
// @lc code=end

