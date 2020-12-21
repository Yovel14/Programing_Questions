ListNode *removeNthFromEnd(ListNode *head, int &n) // exection with two runs
{
	int length = 0;
	ListNode *p = head;

	while (p)
	{
		length++;
		p = p->next;
	}

	if (n == length)
		return head->next;

	length -= n;
	length--; // because it's 1 indexing

	p = head;
	while (length--)
		p = p->next;
	p->next = p->next->next;

	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int &n) // excution using stack
{
	stack<ListNode *> s;
	int length = 0;

	ListNode *t = head;
	while (t)
	{
		s.push(t);
		t = t->next;
		length++;
	}

	if (length == n)
		return head->next;

	while (n--)
		s.pop();
	t = s.top();
	t->next = t->next->next;

	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int &n) // execution with two pointers
{
	ListNode *t1 = head;

	while (t1 && n--)
		t1 = t1->next;

	if (t1 == NULL)
		return head->next;

	ListNode *t2 = head;
	while (t1->next)
	{
		t1 = t1->next;
		t2 = t2->next;
	}
	t2->next = t2->next->next;

	return head;
}