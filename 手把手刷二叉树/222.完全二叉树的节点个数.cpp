#include<iostream>
#include<math.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// Definition for a Node.
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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int hl = 1, hr = 1;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while(l != nullptr){
            hl += 1;
            l = l->left;
        }
        while(r != nullptr){
            hr += 1;
            r = r->right;
        }
        // 完全二叉树必定只有一个分支为满二叉树，一个分支非满二叉树（视为普通），且在非满二叉树上递归，那么该算法的时间复杂度可以达到O(logN*logN)
        // 1. 满二叉树
        if(hl == hr){
            // 讲道理，没想到复杂度优化在这里，位运算tql
            return (2 << hl-1) - 1;
        }
        // 2. 普通二叉树
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end

