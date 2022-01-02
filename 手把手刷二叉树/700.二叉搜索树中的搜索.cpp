/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* res;
    
    TreeNode* searchBST(TreeNode* root, int val){
        traverse(root, val);
        return res;
    }
    
    void traverse(TreeNode* root, int val){
        if (root == nullptr){
            return ;
        }
        if (root->val == val){
            res = root;
            return ;
        }
        else if (root->left != nullptr && root->val > val){
            traverse(root->left, val);
        }
        else if (root->right != nullptr && root->val < val){
            traverse(root->right, val);
        }
    }
};
// @lc code=end

