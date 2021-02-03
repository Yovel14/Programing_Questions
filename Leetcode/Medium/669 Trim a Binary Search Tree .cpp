// Time : O(n) where n is the number of nodes
// Space : O(h) where h is the maximum height
TreeNode *trimBST(TreeNode *root, int &low, int &high)
{
	if (!root)
		return nullptr;

	if (root->val > high)
		return trimBST(root->left, low, high);
	if (root->val < low)
		return trimBST(root->right, low, high);

	root->right = trimBST(root->right, low, high);
	root->left = trimBST(root->left, low, high);
	return root;
}

// Improved with a while loop for reducing depth and thus space and time because iterations are faster than recursion
// Time : O(n) where n is the number of nodes
// Space : O(h) where h is the maximum height
TreeNode *trimBST(TreeNode *root, int &low, int &high)
{
	while (root)
	{
		if (root->val < low)
			root = root->right;
		else if (root->val > high)
			root = root->left;
		else
			break;
	}

	if (!root)
		return nullptr;

	root->right = trimBST(root->right, low, high);
	root->left = trimBST(root->left, low, high);
	return root;
}