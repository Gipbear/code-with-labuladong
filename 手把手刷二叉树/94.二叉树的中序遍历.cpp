#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inorder(root, res);
    //     return res;
    // }

    // void inorder(TreeNode *root, vector<int>& res){
    //     if(root == nullptr){
    //         return ;
    //     }
    //     inorder(root->left, res);
    //     res.emplace_back(root->val);
    //     inorder(root->right, res);
    //     return ;
    // }

    stack<TreeNode*> stk;
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        // 记录上一次遍历完的子树的根结点
        TreeNode *visited = new TreeNode(-1);
        
        pushLeftBranch(root);
        while(!stk.empty()){
            TreeNode *p = stk.top();
            if((p->left == nullptr || p->left == visited) && p->right != visited){
                // ! 中序代码
                res.emplace_back(p->val);
                pushLeftBranch(p->right);
            }
            if(p->right == nullptr || p->right == visited){
                // ! 后序代码
                visited = p;
                stk.pop();
            }
        }
        return res;
    }

    // 一路向左
    void pushLeftBranch(TreeNode *root){
        while (root != nullptr){
            // ! 前序代码
            stk.push(root);
            root = root->left;
        }
        
    }
};
// @lc code=end

