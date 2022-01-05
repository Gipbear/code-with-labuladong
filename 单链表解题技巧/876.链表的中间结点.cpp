/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        ListNode * first = head, * second = head;
        while(first != nullptr && first->next != nullptr){
            // 慢指针走一步，快指针走两步
            second = second->next;
            first = first->next->next;
        }
        return second;
    }
};
// @lc code=end

