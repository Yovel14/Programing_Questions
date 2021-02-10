// Time : O(n)
// Space : O(1)
Node *copyRandomList(Node *head)
{
	if (!head)
		return nullptr;
	Node *r = head;
	Node *tmp;
	while (r)
	{
		tmp = new Node(r->val);
		tmp->next = r->next;
		r->next = tmp;
		r = r->next->next;
	}

	r = head;
	while (r)
	{
		if (r->random)
			r->next->random = r->random->next;
		r = r->next->next;
	}

	Node *nh = head->next;
	r = head;
	Node *r2 = nh;
	while (r2->next)
	{
		r->next = r->next->next;
		r = r->next;
		r2->next = r2->next->next;
		r2 = r2->next;
	}
	r->next = nullptr;

	return nh;
}

// Time : O(n) where n is the number of nodes in the list
// Space : O(n)
Node *copyRandomList(Node *head)
{
	if (!head)
		return nullptr;
	unordered_map<Node *, Node *> m;
	m.insert({nullptr, nullptr});
	Node *setinel = new Node(head->val);
	Node *cr = setinel;
	Node *r = head;
	while (r)
	{
		cr->next = new Node(r->val);
		m.insert({r, cr->next});
		r = r->next;
		cr = cr->next;
	}

	r = head;
	cr = setinel->next;
	while (r)
	{
		cr->random = m[r->random];
		r = r->next;
		cr = cr->next;
	}
	return setinel->next;
}