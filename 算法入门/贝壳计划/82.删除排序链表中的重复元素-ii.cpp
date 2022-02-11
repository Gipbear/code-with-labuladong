/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *dummy = new ListNode(-101);
        dummy->next = head;
        ListNode *pre = dummy, *cur = pre->next, *nxt = cur->next;
        while(nxt != nullptr){
            if(cur->val != nxt->val){
                pre->next = cur;
                pre = cur;
            }
            else{
                while(nxt != nullptr && nxt->val == cur->val)
                    nxt = nxt->next;
            }
            cur = nxt;
            if(nxt != nullptr)
                nxt = nxt->next;
        }
        pre->next = cur;
        return dummy->next;
    }
};
// @lc code=end

