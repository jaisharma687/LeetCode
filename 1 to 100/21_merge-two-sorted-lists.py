# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0)
        current = head
        c1 = list1
        c2 = list2
        while c1 and c2:
            if c1.val < c2.val:
                current.next = c1
                c1 = c1.next
            else:
                current.next = c2
                c2 = c2.next
            current = current.next
        if c1:
            current.next = c1
        if c2:
            current.next = c2
        return head.next
        