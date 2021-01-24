// Time : O(mx_length * n) mx_length is maximum length of the ListNode lists
// space : O(1)
ListNode *merge(ListNode *l1, ListNode *l2)
{
	ListNode *setinel = new ListNode(0);
	ListNode *head = setinel;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			head->next = l1;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			l2 = l2->next;
		}
		head = head->next;
	}
	if (l1)
		head->next = l1;
	else if (l2)
		head->next = l2;
	return setinel->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
	if (lists.size() == 0)
		return nullptr;
	int n = lists.size() - 1;
	for (int i = 0; i < n; i++)
	{
		lists[i + 1] = merge(lists[i], lists[i + 1]);
	}
	return lists[n];
}

// using the Idea of merge sort iterativly
// Time : O(log(n) * mx_length) n as length of lists and mx_length is maximum length of the ListNode lists
// Space : O(1)
ListNode *merge(ListNode *l1, ListNode *l2)
{
	if (!l1)
		return l2;
	if (!l2)
		return l1;
	ListNode *setinel = new ListNode(0);
	ListNode *head = setinel;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			head->next = l1;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			l2 = l2->next;
		}
		head = head->next;
	}
	if (l1)
		head->next = l1;
	else if (l2)
		head->next = l2;
	return setinel->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
	if (lists.size() == 0)
		return nullptr;
	if (lists.size() == 1)
		return lists[0];

	int put_here = 0;
	int last_size = lists.size();
	while (last_size != 1)
	{
		put_here = 0;
		for (int i = 0; i < last_size - 1; i += 2)
		{
			lists[put_here++] = merge(lists[i], lists[i + 1]);
		}
		if (last_size & 1)
		{
			lists[put_here++] = lists[last_size - 1];
		}
		last_size = put_here;
	}
	return lists[0];
}

// recursive like merge sort
// Time : O(n log(mx_length)) mx_length is maximum length of the ListNode lists
// Space : O(1)
ListNode *merge(ListNode *l1, ListNode *l2)
{
	if (!(l1))
		return l2;
	if (!(l2))
		return l1;
	if (l2->val < l1->val)
	{
		l2->next = merge(l1, l2->next);
		return l2;
	}
	l1->next = merge(l1->next, l2);
	return l1;
}
ListNode *mergek(vector<ListNode *> &lists, int l, int r)
{
	if (l > r)
		return nullptr;
	if (l == r)
		return lists[l];
	if (l + 1 == r)
		return merge(lists[l], lists[r]);
	int mid = l + ((r - l) >> 1);
	return merge(mergek(lists, l, mid), mergek(lists, mid + 1, r));
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
	return mergek(lists, 0, lists.size() - 1);
}

// this could be solved with priority queue or some other ds