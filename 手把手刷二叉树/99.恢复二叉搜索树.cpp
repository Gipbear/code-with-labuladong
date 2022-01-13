/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode *t1, *t2, * pre;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }

    void inorder(TreeNode *root){
        if(root == nullptr){
            return ;
        }
        inorder(root->left);
        // 前一个结点大于当前结点：说明反了
        if(pre != nullptr && pre->val > root->val){
            // t1只记录一次
            if(t1 == nullptr)
                t1 = pre;
            t2 = root;
        }
        pre = root;
        inorder(root->right);
    }
};
// @lc code=end

