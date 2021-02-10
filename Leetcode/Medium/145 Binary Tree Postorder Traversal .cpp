// Time : O(n)
// Space : O(n)
vector<int> postorderTraversal(TreeNode *root)
{
	if (!root)
		return {};

	vector<int> v;
	stack<TreeNode *> s;
	s.push(root);
	while (!s.empty())
	{
		root = s.top();
		s.pop();
		v.push_back(root->val);

		if (root->left)
			s.push(root->left);
		if (root->right)
			s.push(root->right);
	}

	reverse(v.begin(), v.end());
	return v;
}
// Time : O(n)
// Space : O(h) where h is the height of the tree
void DFS(TreeNode *root, vector<int> &v)
{
	if (!root)
		return;
	DFS(root->left, v);
	DFS(root->right, v);
	v.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> v;
	DFS(root, v);
	return v;
}