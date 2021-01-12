ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	// the idea is to add both like in long addtion while kipping the reminder

	ListNode *setinel = new ListNode(0);
	ListNode *runer = setinel;
	int sum = 0;
	while (l1 || l2 || sum)
	{
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		if (sum > 9)
		{
			runer->next = new ListNode(sum - 10);
			sum = 1;
		}
		else
		{
			runer->next = new ListNode(sum);
			sum = 0;
		}
		runer = runer->next;
	}
	return setinel->next;
}