/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, tmp;
        ListNode *head = new ListNode(-1), *p = head;
        while(l1 != nullptr && l2 != nullptr){
            tmp = l1->val + l2->val + carry;
            p->next = new ListNode(tmp % 10);
            carry = tmp / 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2 != nullptr){
            l1 = l2;
        }
        while(l1 != nullptr){
            tmp = l1->val + carry;
            p->next = new ListNode(tmp % 10);
            carry = tmp / 10;
            p = p->next;
            l1 = l1->next;
        }
        if(carry == 1){
            p->next = new ListNode(1);
        }
        return head->next;
    }
};
// @lc code=end

