#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个升序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        n = len(lists)
        if n == 0:
            return None
        if n == 1:
            return lists[0]
        res = lists[0]
        
        def mergeTwo(list1, list2):
            dummy = ListNode(-1)
            p = dummy
            p1, p2 = list1, list2
            while p1 and p2:
                if p1.val < p2.val:
                    p.next = p1
                    p1 = p1.next
                else:
                    p.next = p2
                    p2 = p2.next
                p = p.next
            if p1:
                p.next = p1
            if p2:
                p.next = p2
            return dummy.next
        
        for i in range(1, n):
            res = mergeTwo(res, lists[i])
        return res
# @lc code=end

