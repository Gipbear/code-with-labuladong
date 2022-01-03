#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */

//Definition for a binary tree node.

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution{
public:
    int maxsum = 0;
    int maxSumBST(TreeNode *root){
        traverse(root);
        return maxsum;
    }

    vector<int> traverse(TreeNode *node){
        if (node == nullptr){
            // [是否BST, 左最大，右最小，BST和]
            return {1, 40001, -40001, 0};
        }
        vector<int> left = traverse(node->left);
        vector<int> right = traverse(node->right);

        vector<int> res = {0,0,0,0};
        // 判断左右子树是否为BST
        if (left[0] == 1 && right[0] == 1 && node->val > left[2] && node->val < right[1]){
            res[0] = 1;  // 该结点为BST
            res[1] = left[1] < node->val ? left[1] : node->val;
            res[2] = right[2] > node->val ? right[2] : node->val;
            res[3] = left[3] + node->val + right[3];
            maxsum = res[3] > maxsum ? res[3] : maxsum;
        }
        else{
            res[0] = 0;  // 标记该结点不为BST
        }
        return res;
    }
};
// @lc code=end
