class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		//Idea is to add both wile adding to a new linked list
		ListNode *orgin = new ListNode(0);
		ListNode *cur = orgin;
		int sum = 0;
		while (l1 || l2)
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
			cur->next = new ListNode(sum % 10);
			sum /= 10;
			cur = cur->next;
		}
		if (sum != 0)
			cur->next = new ListNode(sum % 10);
		return orgin->next;
	}
};