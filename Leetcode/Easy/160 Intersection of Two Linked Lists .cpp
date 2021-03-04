// Time : O(n + m)
// Space : O(1)
ListNode *getIntersectionNode(ListNode *a, ListNode *b)
{
	int dis = 0;
	ListNode *ra = a;
	ListNode *rb = b;
	while (ra || rb)
	{
		if (ra)
			ra = ra->next;
		else
			dis++;
		if (rb)
			rb = rb->next;
		else
			dis--;
	}

	ra = a;
	rb = b;
	if (dis > 0)
		while (rb && dis--)
			rb = rb->next;
	else
		while (ra && dis++)
			ra = ra->next;

	while (ra && rb && ra != rb)
	{
		ra = ra->next;
		rb = rb->next;
	}
	return (ra && rb ? ra : nullptr);
}

// better implementaion
ListNode *getIntersectionNode(ListNode *a, ListNode *b)
{
	ListNode *ra = a;
	ListNode *rb = b;
	while (ra != rb)
	{
		ra = ra ? ra->next : b;
		rb = rb ? rb->next : a;
	}
	return ra;
}

// Time : O(n + m)
// Space : O(n)
ListNode *getIntersectionNode(ListNode *a, ListNode *b)
{
	unordered_set<ListNode *> s;
	while (a)
	{
		s.insert(a);
		a = a->next;
	}
	while (b)
	{
		if (s.find(b) != s.end())
			return b;
		b = b->next;
	}

	return nullptr;
}