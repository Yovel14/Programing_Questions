// O(n) where n is the number of nodes
// O(n)
bool isSymmetric(TreeNode *root)
{
	if (!root)
		return true;

	queue<TreeNode *> q;
	q.push(root->left);
	q.push(root->right);
	TreeNode *n1;
	TreeNode *n2;
	while (!q.empty())
	{
		n1 = q.front();
		q.pop();
		n2 = q.front();
		q.pop();
		if (!n1 && !n2)
			continue;
		if (!n1 || !n2 || n1->val != n2->val)
			return false;
		q.push(n1->left);
		q.push(n2->right);

		q.push(n1->right);
		q.push(n2->left);
	}
	return true;
}
// Time : O(n) where n is the number of nodes in the tree
// Space : O(n)
bool Symmetric(TreeNode *left, TreeNode *right)
{
	if (!left && !right)
		return true;
	if (!left || !right)
		return false;
	return left->val == right->val && Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
	if (!root)
		return true;
	return Symmetric(root->left, root->right);
}