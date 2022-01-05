#include<iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        // 同样使用快慢指针，若存在环，那么快指针将会在环内与慢指针相遇
        while(first != nullptr && first->next != nullptr){
            first = first->next->next;
            second = second->next;
            if(first == second){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

