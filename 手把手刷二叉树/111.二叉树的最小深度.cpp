#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        // 记录每层的所有结点
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty()){
            int sz = q.size();
            // 遍历队列中的所有结点
            for(int i = 1; i <= sz; i++){
                TreeNode *cur = q.front();
                q.pop();
                // 判断是叶子结点
                if(cur->left == nullptr && cur->right == nullptr)
                    return depth;
                // 有左节点, 加入队列
                if(cur->left != nullptr)
                    q.push(cur->left);
                // 有右节点, 加入队列
                if(cur->right != nullptr)
                    q.push(cur->right);
            }
            depth++;  // 注意! 在这一层遍历结束之后深度加一
        }
        return depth;
    }
};
// @lc code=end

