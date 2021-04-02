// Time : o(n)
// Space : O(1)
inline ListNode *reverse(ListNode *h)
{
	if (!h)
		return h;

	ListNode *prev = nullptr;
	ListNode *next;
	while (h)
	{
		next = h->next;
		h->next = prev;
		prev = h;
		h = next;
	}

	return prev;
}
bool inline isPalindrome(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *half = reverse(slow);
	slow = half;

	bool ans = true;
	while (head && slow)
	{
		if (head->val != slow->val)
		{
			ans = false;
			break;
		}
		head = head->next;
		slow = slow->next;
	}

	reverse(half);

	return ans;
}

// Time : o(n)
// Space : O(n)
ListNode *dfs(ListNode *h1, int length, bool even, bool &pal)
{
	if (length != 0)
	{
		ListNode *tmp = dfs(h1->next, length - 1, even, pal);
		if (tmp == nullptr)
			return nullptr;

		if (h1->val != tmp->val)
		{
			pal = false;
			return nullptr;
		}
		return tmp->next;
	}

	// length == 0
	ListNode *tmp;
	if (even)
		tmp = h1->next;
	else
		tmp = h1->next->next;

	if (h1->val != tmp->val)
	{
		pal = false;
		return nullptr;
	}
	return tmp->next;
}
bool isPalindrome(ListNode *head)
{
	ListNode *r = head;

	int length = 0;
	while (r)
	{
		length++;
		r = r->next;
	}

	if (length < 2)
		return true;

	bool pal = true;
	dfs(head, length / 2 - 1, length % 2 == 0, pal);
	return pal;
}