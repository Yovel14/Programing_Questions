// recursion
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
	if (original == target)
		return cloned;
	if (target == nullptr || original == nullptr)
		return nullptr;

	TreeNode *tt = getTargetCopy(original->right, cloned->right, target);
	if (tt)
		return tt;

	tt = getTargetCopy(original->left, cloned->left, target);
	if (tt)
		return tt;

	return nullptr;
}

// queue
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
	queue<TreeNode *> originalq;
	originalq.push(original);

	queue<TreeNode *> clonedq;
	clonedq.push(cloned);

	int length = 1;
	int tlength = 1;
	int i;
	while (!originalq.empty())
	{
		length = tlength;
		tlength = 0;
		while (length--)
		{
			if (originalq.front() == target)
				return clonedq.front();
			if (originalq.front()->left)
			{
				originalq.push(originalq.front()->left);
				clonedq.push(clonedq.front()->left);
				tlength++;
			}
			if (originalq.front()->right)
			{
				originalq.push(originalq.front()->right);
				clonedq.push(clonedq.front()->right);
				tlength++;
			}
			originalq.pop();
			clonedq.pop();
		}
	}
	return nullptr;
}

// stack
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
	stack<TreeNode *> originals;
	stack<TreeNode *> cloneds;
	TreeNode *no = original;
	TreeNode *nc = cloned;
	while (!originals.empty() || no)
	{
		while (no)
		{
			originals.push(no);
			cloneds.push(nc);

			no = no->left;
			nc = nc->left;
		}
		no = originals.top();
		nc = cloneds.top();
		originals.pop();
		cloneds.pop();
		if (no == target)
			return nc;
		no = no->right;
		nc = nc->right;
	}
	return nullptr;
}
