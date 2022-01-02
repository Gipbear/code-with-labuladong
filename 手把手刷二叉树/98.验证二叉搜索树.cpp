/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

//Definition for a binary tree node.

struct TreeNode
{
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
    // 这是我写的
    // 用全局变量来表示最后的结果，默认为true
    bool flag = true;

    bool isValidBST(TreeNode *root){
        if (flag != true || root == nullptr)
            return flag;
        else if (root->left && root->val <= getMM(root->left, 1))
            flag = false;
        else if (root->right && root->val >= getMM(root->right, 0))
            flag = false;
        if (root->left)
            isValidBST(root->left);
        if (root->right)
            isValidBST(root->right);
        return flag;
    }

    // 得到该结点下的最值
    // 1表示获取最大值，0表示获取最小值
    int getMM(TreeNode *node, int t){
        if (t == 0){
            while (node->left != nullptr)
                node = node->left;
            return node->val;
        }
        else if (t == 1){
            while (node->right != nullptr)
                node = node->right;
            return node->val;
        }
        return 0;
    }

/* 东哥教学
    bool isValidBST(TreeNode *root){
        return isValidBST2(root, nullptr, nullptr);
    }

    bool isValidBST2(TreeNode *root, TreeNode *min, TreeNode *max){
        if (root == nullptr)
            return true;
        if (min != nullptr && root->val <= min->val)
            return false;
        if (max != nullptr && root->val >= max->val)
            return false;
        return isValidBST2(root->left, min, root) && isValidBST2(root->right, root, max);
    }
*/
};
// @lc code=end
