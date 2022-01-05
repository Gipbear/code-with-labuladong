/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(head->next == nullptr){
    //         return nullptr;
    //     }
    //     ListNode* first = head;
    //     ListNode* second = first;
    //     for(int i = 0; i < n; i++){
    //         first = first->next;
    //     }
    //     if(first == nullptr){
    //         return head->next;
    //     }
    //     while(first->next != nullptr){
    //         first = first->next;
    //         second = second->next;
    //     }
    //     second->next = second->next->next;
    //     return head;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //使用头结点
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        // 快慢结点
        ListNode *first = dummy, *second = dummy;
        // first先走n步
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        // first和second保持相同的间距前进
        // first指向终点时second指向将要删除结点的前一个
        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        }
        // 删除（未释放空间）
        second->next = second->next->next;
        return dummy->next;
    }
};
// @lc code=end

