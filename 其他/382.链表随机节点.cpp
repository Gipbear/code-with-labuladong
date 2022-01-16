#include<iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
public:

    ListNode *head;

    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        // 蓄水池抽样法
        ListNode *p = head;
        int count = 1;
        int val = head->val;
        while(p != nullptr){
            if(rand() % count == 0){
                val = p->val;
            }
            count++;
            p = p->next;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

