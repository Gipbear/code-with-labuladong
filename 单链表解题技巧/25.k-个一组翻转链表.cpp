/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        ListNode *begin = head, *end = head;
        // 找到第k个结点
        for(int i = 0; i < k; i++){
            // 不足k个不需要反转
            if(end == nullptr)
                return head;
            end = end->next;
        }
        // 反转前k个结点
        ListNode * newHead = reversePart(begin, end);
        // 递归反转后续链表
        begin->next = reverseKGroup(end, k);
        return newHead;
    }
    
    ListNode* reversePart(ListNode *begin, ListNode * end) {
        ListNode *pre = nullptr, *cur = begin, *nxt=begin;
        while(cur != end){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
// @lc code=end

