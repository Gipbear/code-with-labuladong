#include<iostream>
#include<queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 无链表
        if(lists.size() == 0){
            return nullptr;
        }
        // 仅有一个链表
        if(lists.size() == 1){
            return lists[0];
        }
        // k-1 次两两合并
        ListNode * res = lists[0];
        for(int i = 1; i < lists.size(); i++){
            res = mergeTwoLists(res,lists[i]);
        }
        return res;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
