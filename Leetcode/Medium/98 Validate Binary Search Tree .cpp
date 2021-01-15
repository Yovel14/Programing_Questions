// time O(n) where n is the number of nodes
// space O(n) because we have O(1) at each recursive call
bool isValidBST(TreeNode *root, int smaller_than = INT_MAX, int bigger_than = INT_MIN, bool smaller_defined = false, bool bigger_defined = false)
{
	if (!(root))
		return true;
	if (!((root->val > bigger_than || !bigger_defined) && (root->val < smaller_than || !smaller_defined)))
		return false;
	return isValidBST(root->right, smaller_than, root->val, smaller_defined, true) && isValidBST(root->left, root->val, bigger_than, true, bigger_defined);
}

// time O(n) where n is the number of nodes
// space O(n) because we have O(1) at each recursive call
bool myisValidBST(TreeNode *root, TreeNode *&prev)
{
	if (!root)
		return true;
	if (!myisValidBST(root->left, prev))
		return false;
	if (prev && prev->val >= root->val)
		return false;

	prev = root;
	return myisValidBST(root->right, prev);
}
bool isValidBST(TreeNode *root)
{
	TreeNode *prev = nullptr;
	return myisValidBST(root, prev);
}

// time O(n) where n is the number of nodes
// space O(h) where h is the hight of the tree
bool isValidBST(TreeNode *root)
{
	stack<TreeNode *> ts;
	int prev = INT_MIN;
	bool first = true;

	while (!ts.empty() || root)
	{
		while (root)
		{
			ts.push(root);
			root = root->left;
		}
		root = ts.top();
		ts.pop();

		if (root->val <= prev && !first)
		{
			return false;
		}
		prev = root->val;
		root = root->right;
		first = false;
	}
	return true;
}