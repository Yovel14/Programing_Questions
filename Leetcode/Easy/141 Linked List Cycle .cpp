// Time : O(n + k) where n is the length of the none cycle length and k is the length of the cycle
// n because this is the length time that will take the slow to reach the cycle
// k because assuming an infinite length surface the time that will take fast to catch up to slow is the space between slow and fast over the difference in speed which is 2-1 = 1 (reletive speed)
// (assuming in the surface slow is before fast I can asssume that because it's a cycle)
// Space : O(1)
bool hasCycle(ListNode *slow)
{
	if (!slow)
		return false;
	ListNode *fast = slow->next;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

// Time : O(n) where n is the number of unique nodes
// Space : O(n)
bool hasCycle(ListNode *head)
{
	unordered_set<ListNode *> s;
	while (head)
	{
		if (s.find(head) != s.end())
			return true;
		s.insert(head);
		head = head->next;
	}
	return false;
}