// Time : O(n) where n is the amount of nudes in the tree
// Space : O(w) where w is the maximum number of nodes in a level
int deepestLeavesSum(TreeNode *root)
{
	if (!root)
		return 0;

	queue<TreeNode *> q;
	q.push(root);
	int sum;
	int length;
	while (!q.empty())
	{
		length = q.size();
		sum = 0;
		while (length--)
		{
			root = q.front();
			q.pop();

			sum += root->val;
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
	}
	return sum;
}

// could also be solved with dfs