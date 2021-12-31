#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, inorder.size()-1, inorder, 0, inorder.size()-1);
    }

    // 增加前序数组区间
    // 增加中序遍历区间
    TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int inlow, int inhigh){
        // base case
        if (prestart > preend){
            return nullptr;
        }

        // 找到中序遍历数组中的先序遍历数组的第一个
        int mid = inlow;
        for(int i = inlow; i <= inhigh; i++){
            if (inorder[i] == preorder[prestart]){
                mid = i;
                break;
            }
        }
        // 先序遍历的数组大小做限制
        int growSize = mid - inlow;

        // 创建结点
        TreeNode* node = new TreeNode(preorder[prestart]);

        node->left = build(preorder, prestart+1, prestart+growSize, inorder, inlow, mid-1);
        node->right = build(preorder, prestart+growSize+1, preend, inorder, mid+1, inhigh);

        return node;
    }
};
// @lc code=end

