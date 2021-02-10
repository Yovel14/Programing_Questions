// moris inorder traversal
// Time : O(n) where n is the number of nodes in the tree
// Space : O(n) because of the vector
vector<int> inorderTraversal(TreeNode *cur)
{
	vector<int> v;
	TreeNode *tmp;

	while (cur)
	{
		if (cur->left)
		{
			tmp = cur->left;
			while (tmp->right && tmp->right != cur)
				tmp = tmp->right;

			if (tmp->right)
			{
				tmp->right = nullptr;
				v.push_back(cur->val);
				cur = cur->right;
			}
			else
			{
				tmp->right = cur;
				cur = cur->left;
			}
		}
		else
		{
			v.push_back(cur->val);
			cur = cur->right;
		}
	}

	return v;
}

// Time : O(n)
// Space : O(n)
void DFS(TreeNode *root, vector<int> &v)
{
	if (!root)
		return;
	DFS(root->left, v);
	v.push_back(root->val);
	DFS(root->right, v);
}
vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> v;
	DFS(root, v);
	return v;
}

// Stack
// Time : O(n)
// Space : O(1)
vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> v;
	stack<TreeNode *> s;

	while (!s.empty() || root)
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}

		v.push_back(s.top()->val);
		root = s.top()->right;
		s.pop();
	}
	return v;
}