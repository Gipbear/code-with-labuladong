#include<iostream>
#include<queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
class Solution {
public:
    // Node* connect(Node* root) {
    //     if(root == nullptr){
    //         return nullptr;
    //     }
    //     root->next = nullptr;
    //     traverse(root->left, root->right);
    //     return root;
    // }

    // void traverse(Node *l, Node *r){
    //     if(l == nullptr)
    //         return ;
    //     l->next = r;
    //     traverse(l->left, l->right);
    //     traverse(l->right, r->left);
    //     traverse(r->left, r->right);
    // }

    Node* connect(Node* root) {
        queue<Node*> q;
        if(root != nullptr){
            q.push(root);
        }
        while(!q.empty()){
            int q_len = q.size();
            for(int i = 0; i < q_len; i++){
                // 取出一个结点
                Node *node = q.front();
                q.pop();
                // 该行还有后续结点, 则指向队列第一个
                if(i < q_len-1)
                    node->next = q.front();
                // 左右结点入栈
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
        }
        return root;
    }

};
// @lc code=end

