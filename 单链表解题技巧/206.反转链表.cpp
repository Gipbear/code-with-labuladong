/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // ListNode* reverseList(ListNode* head) {
    //     if(head == nullptr)
    //         return nullptr;
    //     ListNode *h = nullptr;
    //     ListNode * p = head, *q = head;
    //     while(p != nullptr && p->next != nullptr){
    //         q = p->next;
    //         p->next = h;
    //         h = p;
    //         p = q;
    //     }
    //     p->next = h;
    //     return p;
    // }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 使用last指向翻转head后的链表
        ListNode *last = reverseList(head->next);
        // 这里需要画个图才能解释
        head->next->next = head;
        // 最后head去指向空
        head->next = nullptr;
        return last;
    }
};
// @lc code=end

