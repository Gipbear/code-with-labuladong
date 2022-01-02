/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// Definition for a binary tree node.

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
    int count = 0;
    int result = 0;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return result;
    }
    void traverse(TreeNode* root, int k){
        if (root == nullptr){
            return;
        }
        kthSmallest(root->left, k);
        count++;
        if (k == count){
            result = root->val;
            return;
        }
        kthSmallest(root->right,k);
    }
};
// @lc code=end

