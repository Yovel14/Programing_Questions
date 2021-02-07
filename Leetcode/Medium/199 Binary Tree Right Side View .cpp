// Time : O(n) where n is the number of TreeNodes in root
// Space : O(h) where h is the height of the tree
void add_rightmost_at_each_level(TreeNode *root, int level, vector<int> &v)
{
	if (!root)
		return;
	if (v.size() < level)
		v.push_back(root->val);
	level++;
	add_rightmost_at_each_level(root->right, level, v);
	add_rightmost_at_each_level(root->left, level, v);
}
vector<int> rightSideView(TreeNode *root)
{
	// get the rights most at each level
	vector<int> v;
	add_rightmost_at_each_level(root, 1, v);
	return v;
}