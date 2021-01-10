bool solve(int &n, vector<int> &ans, bool used[], int index)
{
	if (index == ans.size())
		return true;
	if (ans[index] != -1)
		return solve(n, ans, used, index + 1);
	for (int i = n; i > 0; i--)
	{
		if (used[i] || i != 1 && (index + i >= ans.size() || ans[index + i] != -1))
			continue;

		used[i] = true;
		ans[index] = i;
		if (i != 1)
			ans[index + i] = i;
		if (solve(n, ans, used, index + 1))
			return true;
		used[i] = false;
		ans[index] = -1;
		if (i != 1)
			ans[index + i] = -1;
	}
	return false;
}
vector<int> constructDistancedSequence(int n)
{
	bool used[n + 1];
	memset(used, 0, sizeof(used));
	vector<int> ans(2 * (n - 1) + 1, -1);
	solve(n, ans, used, 0);

	return ans;
}