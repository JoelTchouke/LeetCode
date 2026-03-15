# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head == None:
            return None
        previousNode = None
        while(head.next != None):
            nextNode = head.next
            head.next = previousNode
            previousNode = head
            head = nextNode
        head.next = previousNode
        return head