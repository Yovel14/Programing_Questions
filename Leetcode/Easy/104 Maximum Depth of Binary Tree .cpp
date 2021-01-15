// time : O(n) where n is the number of nodes in the tree
// space : O(n) since we keep root at each recursive call
int maxDepth(TreeNode *root)
{
	if (!(root))
		return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// time : O(n) where n is the number of nodes in the tree
// space : O(1)
int maxDepth(TreeNode *root)
{
	if (!(root))
		return 0;

	queue<TreeNode *> tq;
	tq.push(root);
	int mx_hight = 0; // starts at zero instead of one because when exiting we count not adding any new nods thus we start at 0
	int cur_length = 1;
	int temp_length;
	TreeNode *t;

	while (!tq.empty())
	{
		temp_length = 0;
		while (cur_length--)
		{
			t = tq.front();
			tq.pop();
			if (t->left)
			{
				temp_length++;
				tq.push(t->left);
			}
			if (t->right)
			{
				temp_length++;
				tq.push(t->right);
			}
		}

		cur_length = temp_length;

		mx_hight++;
	}

	return mx_hight;
}
