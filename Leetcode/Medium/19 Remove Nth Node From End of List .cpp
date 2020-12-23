ListNode *removeNthFromEnd(ListNode *head, int &n) // exection with two runs
{
	int length = 0;
	ListNode *p = head;

	while (p) // find length
	{
		length++;
		p = p->next;
	}

	if (n == length) // check if need to remove the first node
		return head->next;

	length -= n;
	length--;

	p = head;
	while (length--) // get p the node before the n-th from the end
		p = p->next;
	p->next = p->next->next; // the move the node

	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int &n) // excution using stack
{
	stack<ListNode *> s;
	int length = 0;

	ListNode *t = head;
	while (t) // push all nodes
	{
		s.push(t);
		t = t->next;
		length++;
	}

	if (length == n) // if need to remove the first node
		return head->next;

	while (n--) // get the n-1 node from the end
		s.pop();
	t = s.top();
	t->next = t->next->next; // remove the node

	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int &n) // execution with two pointers
{
	ListNode *t1 = head;

	while (t1 && n--) // get t1 to the  n+1 node thus the difference between t1 and t2 is n at all times
		t1 = t1->next;

	if (t1 == NULL) // if need to remove teh first Node
		return head->next;

	ListNode *t2 = head;
	while (t1->next) // find the node before n-th from the end
	{
		t1 = t1->next;
		t2 = t2->next;
	}
	t2->next = t2->next->next;

	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int &n) // Recursion
{
	if (head == NULL) // if end
		return NULL;

	head->next = removeNthFromEnd(head->next, n); // set to the next node

	if (--n == 0) // do I need to remove this node
		return head->next;
	return head;
}