#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode *la = headA, *lb = headB;
    //     ListNode *lc, *llong, *lshort;
    //     // 依旧是快慢指针
    //     // la和lb同时前进
    //     while(la != nullptr && lb != nullptr){
    //         la = la->next;
    //         lb = lb->next;
    //     }
    //     // 选出长链和短链
    //     if(lb != nullptr){
    //         llong = lb;
    //         lc = headB;
    //         lshort = headA;
    //     }
    //     else{
    //         llong = la;
    //         lc = headA;
    //         lshort = headB;
    //     }
    //     // 指向长链的快指针带着慢指针走到头
    //     while(llong != nullptr){
    //         llong = llong->next;
    //         lc = lc->next;
    //     }
    //     //短链从头开始和后出发的慢指针同时前进即可找到相同点
    //     while(lshort != nullptr){
    //         if(lshort == lc){
    //             return lc;
    //         }
    //         lshort = lshort->next;
    //         lc = lc->next;
    //     }
    //     return nullptr;
    // }

    // 东哥思路：链表逻辑相连，一一比较即可(太强了)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *la = headA, *lb = headB;
        while(la != lb){
            if (la != nullptr)
                la = la->next;
            else
                la = headB;
            if (lb != nullptr)
                lb = lb->next;
            else
                lb = headA;
        }
        return la;
    }

};
// @lc code=end

