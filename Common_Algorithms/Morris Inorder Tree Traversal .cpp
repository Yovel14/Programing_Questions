TreeNode *Morris_Inorder_Traversal(TreeNode *root)
{
	TreeNode *cur = root;
	TreeNode *tmp;
	while (cur)
	{
		if (cur->left)
		{
			tmp = cur->left;
			while (tmp->right && tmp->right != cur)
				tmp = tmp->right;

			if (!tmp->right)
			{
				tmp->right = cur;
				cur = cur->left;
			}
			else
			{
				tmp->right = nullptr;
				cout << cur->val << ' ';
				cur = cur->right;
			}
		}
		else
		{
			cout << cur->val << ' ';
			cur = cur->right;
		}
	}
	return root;
}