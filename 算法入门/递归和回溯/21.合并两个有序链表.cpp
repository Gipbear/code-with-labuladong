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
        ListNode *dummy = new ListNode(-1);
        ListNode *d = dummy;
        ListNode *l1 = list1, *l2 = list2;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                d->next = l1;
                l1 = l1->next;
            }
            else{
                d->next = l2;
                l2 = l2->next;
            }
            d = d->next;
        }
        if(l1 != nullptr){
            d->next = l1;
        }
        if(l2 != nullptr){
            d->next = l2;
        }
        return dummy->next;
    }
};
// @lc code=end

