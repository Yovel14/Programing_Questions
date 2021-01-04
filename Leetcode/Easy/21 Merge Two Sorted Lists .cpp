ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	/* there is no need for those ifs
        // the reason for that is that I am checking if both are not null in the while thus they will not gon in
        // furthermore I am checking in the end if if 1 of one of them is not null and adding it to the run
        // if both are null than the next of h is null
        if(!(l1))
            return l2;
        if(!(l2))
            return l1;
        
        */

	ListNode *h = new ListNode();
	ListNode *run = h;

	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			run->next = l2;
			l2 = l2->next;
		}
		else
		{
			run->next = l1;
			l1 = l1->next;
		}
		run = run->next;
	}

	if (l1)
		run->next = l1;
	else if (l2)
		run->next = l2;
	return h->next;
}

// recursive soluiton
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if (!(l1))
		return l2;
	if (!(l2))
		return l1;
	if (l2->val < l1->val)
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
	l1->next = mergeTwoLists(l1->next, l2);
	return l1;
}