def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    if not l1:
        if not l2:
            return None
        return l2
    elif not l2:
        return l1
    if l1.val>l2.val:
        l1,l2 = l2,l1
    l1n = l1
    l2n = l2
    while l1n.next and l2n:
        if l1n.next.val>l2n.val:
            t = l2n
            l2n = l2n.next
            t.next = l1n.next
            l1n.next = t
        l1n = l1n.next
    if l2n:
        l1n.next = l2n
    return l1