#Problem Number 2

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        temp = ListNode(0)
        result = temp
        while (l1 != None or l2 != None):
            val = carry
            if (l1):
                val += l1.val
                l1 = l1.next
            if (l2):
                val += l2.val
                l2 = l2.next
            temp.next = ListNode(val % 10)
            temp = temp.next
            carry = int(val / 10)

        if carry > 0:
            temp.next = ListNode(carry)
        return result.next
    


