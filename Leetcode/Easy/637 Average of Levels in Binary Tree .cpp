// Time : O(n) where n is the amount of nodes in the tree
// Space : O(max(w,h)) where w is the maximum amount of nodes at a level and h is the height of the tree
vector<double> averageOfLevels(TreeNode *root)
{
	if (!root)
		return {};

	vector<double> ans;
	queue<TreeNode *> q;
	q.push(root);
	double sum = 0;
	int length;
	int tmplength = 1;
	while (!q.empty())
	{
		sum = 0;
		length = tmplength;
		tmplength = 0;
		for (int i = 0; i < length; i++)
		{
			root = q.front();
			q.pop();
			sum += root->val;

			if (root->left)
			{
				tmplength++;
				q.push(root->left);
			}
			if (root->right)
			{
				tmplength++;
				q.push(root->right);
			}
		}
		ans.push_back((double)(sum) / length);
	}

	return ans;
}

// could also be done in DFS and in reverse morris traversal