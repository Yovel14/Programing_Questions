// Time : O(n)
// Space : O(1)
ListNode *partition(ListNode *head, int x)
{
	ListNode *beforeBase = new ListNode(-1, nullptr);
	ListNode *b = beforeBase;
	ListNode *afterBase = new ListNode(-1, nullptr);
	ListNode *a = afterBase;

	while (head)
	{
		if (head->val < x)
		{
			b->next = head;
			b = b->next;
		}
		else
		{
			a->next = head;
			a = a->next;
		}

		head = head->next;
	}

	b->next = afterBase->next;
	a->next = nullptr;

	return beforeBase->next;
}