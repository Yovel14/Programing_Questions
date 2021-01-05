// iterative
ListNode *deleteDuplicates(ListNode *head)
{
	ListNode *setinel = new ListNode(0, head);

	ListNode *last_good = setinel;
	while (head)
	{
		if (head->next && head->val == head->next->val)
		{
			while (head->next && head->val == head->next->val)
				head = head->next;
			last_good->next = head->next;
		}
		else
			last_good = last_good->next;
		head = head->next;
	}
	return setinel->next;
}

// recursive
ListNode *deleteDuplicates(ListNode *head)
{
	if (!(head))
		return nullptr;
	if (!(head->next))
		return head;

	if (head->val == head->next->val)
	{
		while (head->next && head->val == head->next->val)
			head = head->next;
		return deleteDuplicates(head->next);
	}

	head->next = deleteDuplicates(head->next);
	return head;
}