/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

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
    TreeNode* invertTree(TreeNode* root) {
        
        // base case
        if (root == nullptr){
            return nullptr;
        }

        // 交换该结点的左右子树
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        /*以上在子树遍历之间操作，属于先序遍历
        本题使用后续遍历也可以*/

        // 递归左右子树
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
// @lc code=end

