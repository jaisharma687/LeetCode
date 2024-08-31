# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        visited = []
        current = head
        prev = ListNode(0)
        while current:
            if current.val not in visited:
                visited.append(current.val)
                prev = current
                current = current.next
            else:
                prev.next = current.next
                current = prev.next
        return head
        