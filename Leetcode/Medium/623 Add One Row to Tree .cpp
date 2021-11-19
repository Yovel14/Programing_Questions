// Time : O(n) where n is the number of nudes until d
// Space : O(d) where d is the depth
void DFS(TreeNode *root, int &v, int d)
{
	if (!root)
		return;
	if (d == 0)
	{
		root->left = new TreeNode(v, root->left, nullptr);
		root->right = new TreeNode(v, nullptr, root->right);
		return;
	}

	d--;
	DFS(root->left, v, d);
	DFS(root->right, v, d);
}
TreeNode *addOneRow(TreeNode *root, int v, int d)
{
	if (d == 1)
		root = new TreeNode(v, root, nullptr);
	else
		DFS(root, v, d - 2);
	return root;
}

// BFS
// Time : O(n) where n is the number of nudes until d
// Space : O(m) where m is the max number of nudes in a hieght on the tree until depth d
TreeNode *addOneRow(TreeNode *root, int v, int d)
{
	if (!root)
		return root;
	if (d == 1)
	{
		root = new TreeNode(v, root, nullptr);
		return root;
	}
	TreeNode *base = root;
	queue<TreeNode *> q;
	q.push(root);
	int length;
	d -= 2;
	while (!q.empty())
	{
		length = q.size();
		while (length--)
		{
			root = q.front();
			q.pop();
			if (d == 0)
			{
				root->left = new TreeNode(v, root->left, nullptr);
				root->right = new TreeNode(v, nullptr, root->right);
			}
			else
			{
				if (root->left)
					q.push(root->left);
				if (root->right)
					q.push(root->right);
			}
		}
		d--;
	}
	return base;
}