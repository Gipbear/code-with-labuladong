#include<iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        bool flag = false;
        while(first != nullptr && first->next != nullptr){
            first = first->next->next;
            second = second->next;
            if(second == first){
                flag = true;
                break;
            }
        }
        if(flag){
            first = head;
            while(first != second){
                first = first->next;
                second = second->next;
            }
            return second;
        }
        return nullptr;
    }
};
// @lc code=end

