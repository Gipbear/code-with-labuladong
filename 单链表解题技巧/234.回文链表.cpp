#include<iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != nullptr)
            slow = slow->next;
        // 翻转后半段
        ListNode *left = head, *right = reverse(slow);
        while(right != nullptr){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode* reverse(ListNode *head){
        ListNode *pre = nullptr, *cur = head, *nxt;
        while(cur != nullptr){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

// class Solution {
// public:
//     ListNode *left;
//     bool isPalindrome(ListNode* head) {
//         left = head;
//         return traverse(head);
//     }

//     bool traverse(ListNode* right){
//         if(right == nullptr)
//             return true;
//         bool res = traverse(right->next);
//         res = res && (right->val == left->val);
//         left = left->next;
//         return res;
//     }
// };
// @lc code=end

