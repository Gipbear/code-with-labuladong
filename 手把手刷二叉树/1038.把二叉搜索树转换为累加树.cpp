/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
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
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }

    int cumsum = 0;
    void traverse(TreeNode* root){
        if (root == nullptr){
            return;
        }
        traverse(root->right);
        cumsum = root->val + cumsum;
        root->val = cumsum;
        traverse(root->left);
    }
};
// @lc code=end

