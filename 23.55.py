# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ans = ListNode(None)
        a_p = ans
        p = l1
        q = l2
        while p and q:
            if p.val < q.val:
                a_p.next = p
                while p and p.val < q.val:
                    p = p.next
                    a_p = a_p.next
            else:
                a_p.next = q
                while q and q.val <= p.val:
                    q = q.next
                    a_p = a_p.next
        a_p.next = p or q
        return ans.next

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
            return []
        if len(lists) == 1:
            return lists[0]
        ans = []
        i = 1
        while i < len(lists):
            ans.append(self.mergeTwoLists(lists[i-1],lists[i]))
            i += 2
        if i != len(lists) + 1:
            ans.append(lists[i-1])
        return self.mergeKLists(ans)
