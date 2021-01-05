// solution 1
ListNode *deleteDuplicates(ListNode *head)
{
	if (!(head))
		return nullptr;
	ListNode *r1 = head;
	ListNode *r2 = head->next;
	while (r2)
	{
		if (r1->val != r2->val)
		{
			r1->next = r2;
			r1 = r1->next;
		}
		r2 = r2->next;
	}
	r1->next = nullptr;
	return head;
}

// solution 2
ListNode *deleteDuplicates(ListNode *head)
{
	if (!(head))
		return nullptr;
	ListNode *r1 = head;
	while (r1->next)
	{
		if (r1->val == r1->next->val)
		{
			r1->next = r1->next->next;
		}
		else
			r1 = r1->next;
	}
	return head;
}

// solution 3: recursive
ListNode *deleteDuplicates(ListNode *head)
{
	// the Idea here is to keep the last of the duplicates

	if (!(head))
		return nullptr;
	if (!(head->next))
		return head;
	if (head->val != head->next->val)
	{
		head->next = deleteDuplicates(head->next);
		return head;
	}
	return deleteDuplicates(head->next);
}