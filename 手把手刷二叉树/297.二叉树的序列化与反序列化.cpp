#include<iostream>
#include<sstream>
using namespace std;

/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "#";
        }
        string s = to_string(root->val) + ' ' + serialize(root->left) +' '+ serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return traverse(ss);
    }
    
    TreeNode* traverse(stringstream& data){
        string tmp;
        data >> tmp;
        if(tmp == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tmp));
        root->left = traverse(data);
        root->right = traverse(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

