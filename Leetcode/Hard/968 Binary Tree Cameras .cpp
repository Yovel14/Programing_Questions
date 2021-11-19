// Time  : O(n)
// Space : O(h)
int cameras;
int dfs(TreeNode *root)
{
	if (!root)
	{
		return 1;
	}

	int leftChildState = dfs(root->left);
	int rightChildState = dfs(root->right);
	if (leftChildState == -1 || rightChildState == -1)
	{
		cameras++;
		return 0;
	}
	if (leftChildState == 0 || rightChildState == 0)
	{
		return 1;
	}
	return -1;
}
int minCameraCover(TreeNode *root)
{
	cameras = 0;
	if (dfs(root) == -1)
	{
		cameras++;
	}

	return cameras;
}