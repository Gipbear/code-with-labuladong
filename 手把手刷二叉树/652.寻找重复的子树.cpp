#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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

    unordered_map<string, int> memo;
    vector<TreeNode*> res;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode* root){
        if(root == nullptr){
            return "#";
        }

        // 为了清楚树的结构，对该树序列化
        // 此处选择使用后序遍历
        string subTree = traverse(root->left) +"," + traverse(root->right) + "," + to_string(root->val);

        // 等于1时说明之前已经存在过了，
        // 而且之后还有的重复的也只计算一次
        if(memo[subTree] == 1){
            res.emplace_back(root);
        }
        memo[subTree]++;

        return subTree;
    }
};
// @lc code=end

