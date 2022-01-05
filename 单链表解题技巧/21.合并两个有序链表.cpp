/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 原来这个dummy是叫头结点
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* p1 = list1, *p2 = list2;
        while(p1 && p2){
            if(p1->val > p2->val){
                p->next = p2;
                p2 = p2->next;
            }
            else{
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }
        if(p1)
            p->next = p1;
        if(p2)
            p->next = p2;
        return dummy->next;
    }
};
// @lc code=end

