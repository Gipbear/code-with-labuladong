/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1)
            return reverseTop(head, right);
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }

    ListNode * rest;
    ListNode* reverseTop(ListNode* head, int n){
        if(n == 1){
            rest = head->next;
            return head;
        }
        ListNode * last = reverseTop(head->next, n-1);
        head->next->next = head;
        head->next = rest;
        return last;
    }
};
// @lc code=end

