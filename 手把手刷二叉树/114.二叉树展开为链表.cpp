/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == nullptr){
            return ;
        }

        flatten(root->left);
        flatten(root->right);

        // 后序遍历，此处已被展开
        // 1. 将root的左右结点拿出
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // 2. 将左子树置空，右子树换成左子树
        root->left = nullptr;
        root->right = left;

        // 3. 把原先的右子树接到当前右子树的末端
        TreeNode* p = root;
        while (p->right != nullptr){
            p = p->right;
        }
        p->right = right;
    }
};
// @lc code=end

