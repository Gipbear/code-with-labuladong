#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

    // 因为需要将数组划分区间，所以需要使用一个具有范围的区间的，
    TreeNode* build(vector<int> & nums, int low, int high){
        // base case
        if (low > high){
            return nullptr;
        }
        // 寻找数组区间中的最大值索引
        int maxval = low;
        for (int i = low+1; i <= high; i++){
            if (nums[i] > nums[maxval]){
                maxval = i;
            }
        }

        // 创建最大值索引结点
        TreeNode* root = new TreeNode(nums[maxval]);
        
        // 分析该树生成为前序遍历
        root->left = build(nums, low, maxval-1);
        root->right = build(nums, maxval+1, high);
        return root;
    }
};
// @lc code=end

