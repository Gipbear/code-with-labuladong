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
        // 头结点
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* p1 = list1, *p2 = list2;
        // 谁的结点小就将谁接在链表 dummy 后
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
        // 跳出 while 循环的条件必然是至少一条链遍历结束了，那么剩下的一条的后续部分直接接在 dummy 中即可。
        if(p1)
            p->next = p1;
        if(p2)
            p->next = p2;
        // 题目需要返回的是没有头结点的，所以是 next。
        return dummy->next;
    }
};
// @lc code=end

