# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:#O(n) time; O(1) space
        
            #find mid
            fast = head
            slow = head
            while(fast and fast.next):
                slow = slow.next
                fast = fast.next.next

            # reverse second half
            cur = slow
            prev = None
            nex = None
            while(cur):
                nex = cur.next
                cur.next = prev
                prev = cur
                cur = nex

            # check if palindrome
            cur = prev

            while(cur and head):
                if(cur.val!=head.val): 
                    return False
                cur = cur.next
                head = head.next

            # keep in mind (this function ruins the linked list) if you need to use the list after the function runs you need to keep the head and reverse the second half again and connect it with the first half

            return True
