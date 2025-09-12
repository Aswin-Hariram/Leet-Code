# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        # Handle the edge case of an empty list
        if not head:
            return head

        current = head
        
        # Traverse the list until the end
        while current and current.next:
            # If the current node's value is the same as the next node's
            if current.val == current.next.val:
                # Skip the duplicate node by reassigning the next pointer
                current.next = current.next.next
            else:
                # If values are different, move to the next node
                current = current.next
                
        return head
