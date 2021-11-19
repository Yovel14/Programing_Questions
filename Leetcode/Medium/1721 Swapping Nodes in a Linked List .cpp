// swap nodes refrence
// Time : O(n)
// Space : O(1)
ListNode *swapNodes(ListNode *head, int k)
{
	ListNode *setinel = new ListNode(-1, head);
	ListNode *r1 = setinel;
	for (int i = 1; i < k; i++)
		r1 = r1->next;

	ListNode *kFromBeg = r1;
	ListNode *kFromEnd = setinel;
	r1 = r1->next;
	while (r1->next)
	{
		r1 = r1->next;
		kFromEnd = kFromEnd->next;
	}
	if (kFromBeg == kFromEnd->next)
	{
		ListNode *tmp = kFromBeg;
		kFromBeg = kFromEnd;
		kFromEnd = tmp;
	}
	if (kFromBeg->next == kFromEnd)
	{
		ListNode *t1 = kFromEnd->next;
		ListNode *t2 = t1->next;
		kFromBeg->next = t1;
		kFromEnd->next = t2;
		t1->next = kFromEnd;

		return setinel->next;
	}

	ListNode *t1 = kFromBeg->next;
	ListNode *t2 = kFromEnd->next;
	ListNode *t3 = t2->next;
	kFromBeg->next = t2;
	kFromEnd->next = t1;
	t2->next = t1->next;
	t1->next = t3;

	return setinel->next;
}

// Swap nodes value
// Time : O(n)
// Space : O(1)
ListNode *swapNodes(ListNode *head, int k)
{
	ListNode *r1 = head;
	for (int i = 1; i < k; i++) // note k<=n
		r1 = r1->next;

	ListNode *kFromBeg = r1;
	ListNode *kFromEnd = head;
	while (r1->next)
	{
		r1 = r1->next;
		kFromEnd = kFromEnd->next;
	}

	int tmp = kFromBeg->val;
	kFromBeg->val = kFromEnd->val;
	kFromEnd->val = tmp;

	return head;
}