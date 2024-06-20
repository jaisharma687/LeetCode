# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        current = head
        length = 0
        while current:
            current = current.next
            length += 1
        d = length - n
        if d == 0:
            return head.next
        current = head
        prev = ListNode(0)
        while d>0:
            prev = current
            current = current.next
            d -= 1
        prev.next = current.next
        return head
        