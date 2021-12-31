#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    // 与105类似，只需要注意边界不同
    TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend){
        if (poststart > postend){
            return nullptr;
        }

        int mid = instart;
        for (int i = instart; i <= inend; i++){
            if (inorder[i] == postorder[postend]){
                mid = i;
                break;
            }
        }

        int width = mid - instart;

        // 新增结点
        TreeNode* node = new TreeNode(postorder[postend]);
        node->left = build(inorder, instart, instart+width, postorder, poststart, poststart+width-1);
        node->right = build(inorder, instart+width+1, inend, postorder, poststart+width, postend-1);

        return node;
    }
};
// @lc code=end

