// Time : O(n)
// Space : o(1)
bool DFS(TreeNode *root, vector<int> &voyage, int &index, vector<int> &ans)
{
	if (index == voyage.size())
		return true;

	if (root->left)
	{
		if (root->left->val != voyage[index] && !(root->right && root->right->val == voyage[index]))
			return false;

		index++;
		if (!DFS(root->left, voyage, index, ans))
			return false;
	}

	if (root->right)
	{
		if (root->right->val != voyage[index])
			return false;
		index++;
		if (!DFS(root->right, voyage, index, ans))
			return false;
	}

	return true;
}

vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
{
	int n = voyage.size();
	if (n != 0 && (!root || voyage[0] != root->val))
		return {-1};
	if (n == 0)
		return {};

	int index = 1;
	vector<int> ans(voyage.size());
	ans.resize(0);
	if (!DFS(root, voyage, index, ans))
		return {-1};
	return ans;
}