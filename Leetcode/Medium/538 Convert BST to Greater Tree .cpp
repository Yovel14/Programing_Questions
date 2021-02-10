// Morris Reverse order traversal
// Time : O(n) where n is the number of nodes in the tree
// Space : O(1)
TreeNode *convertBST(TreeNode *root)
{
	TreeNode *cur = root;
	TreeNode *tmp;
	int sum = 0;
	while (cur)
	{
		if (cur->right)
		{
			tmp = cur->right;
			while (tmp->left && tmp->left != cur)
				tmp = tmp->left;

			if (tmp->left)
			{
				tmp->left = nullptr;
				sum += cur->val;
				cur->val = sum;
				cur = cur->left;
			}
			else
			{
				tmp->left = cur;
				cur = cur->right;
			}
		}
		else
		{
			sum += cur->val;
			cur->val = sum;
			cur = cur->left;
		}
	}
	return root;
}

// Time : O(n) where n is the number of nodes in the tree
// Space : O(h) where h is the height of the tree
void DFS(TreeNode *root, int &sum)
{
	if (!root)
		return;

	DFS(root->right, sum);
	sum += root->val;
	cout << sum << ' ';
	root->val = sum;
	DFS(root->left, sum);
}
TreeNode *convertBST(TreeNode *root)
{
	int sum = 0;
	DFS(root, sum);
	return root;
}