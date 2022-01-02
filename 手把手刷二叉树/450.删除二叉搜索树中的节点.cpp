/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if (root == nullptr){
            return nullptr;
        }
        if(root->val == key){
            // 只有右结点（或是叶子节点，结果一样）
            if(root->left == nullptr){
                return root->right;
            }
            // 只有左结点
            if(root->right == nullptr){
                return root->left;
            }

            //用右侧最小结点来代替将要删除的结点
            TreeNode* minNode = getMin(root->right);
            root->right = deleteNode(root->right, minNode->val);
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;

        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    // 获取最小结点
    TreeNode* getMin(TreeNode* node){
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
};
// @lc code=end

