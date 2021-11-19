// Time : O(n) where n is the number of nodes int the tree
// Space : O(h) where h is the height of the tree
void pre(Node *root, vector<int> &ans)
{
	if (!root)
		return;
	ans.push_back(root->val);

	for (Node *n : root->children)
		pre(n, ans);
}

vector<int> preorder(Node *root)
{
	vector<int> ans;
	pre(root, ans);
	return ans;
}