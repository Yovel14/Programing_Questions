//space : O((min(can)/target)^n)
void dfs(vector<int> &can, int index, int target, vector<int> &pa, vector<vector<int>> &ans)
{
	if (target == 0)
	{
		ans.push_back(pa);
		return;
	}
	if (index == can.size())
		return;
	if (target < can[index])
		return;
	dfs(can, index + 1, target, pa, ans);
	int count = 0;
	for (int sum = can[index]; sum <= target; sum += can[index])
	{
		pa.push_back(can[index]);
		count++;
		dfs(can, index + 1, target - sum, pa, ans);
	}
	while (count--)
		pa.pop_back();
}
vector<vector<int>> combinationSum(vector<int> &can, int target)
{
	vector<vector<int>> ans;
	vector<int> pa;
	sort(can.begin(), can.end());
	dfs(can, 0, target, pa, ans);
	return ans;
}